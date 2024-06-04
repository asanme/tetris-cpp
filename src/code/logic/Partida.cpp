#include <fstream>
#include "headers/InfoJoc.h"
#include "headers/Figura.h"
#include "headers/Partida.h"
#include "../util/headers/Utilities.h"

void Partida::inicialitza(
	GameMode gameMode,
	const string& fitxerInicial,
	const string& fitxerFigures,
	const string& fitxerMoviments
)
{
	switch (gameMode)
	{
	case NORMAL:
		initNormalGame();
		break;
	case AUTOMATED:
		initAutomatedGame(fitxerInicial, fitxerFigures, fitxerMoviments);
		break;
	}
}

void Partida::actualitza(GameMode gameMode, double deltaTime)
{
	renderBackground();
	renderNextShapes();
	renderGame();

	if (!m_hasGameFinished)
	{
		switch (gameMode)
		{
		case NORMAL:
			normalGame(deltaTime);
			break;

		case AUTOMATED:
			automatedGame(deltaTime);
			break;
		}
	}
}
void Partida::renderBackground() const
{
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
}

// End condition for normal games is topOut
void Partida::normalGame(double deltaTime)
{
	if (!m_hasGameFinished)
		handleGameInput();

	m_time += deltaTime;
	if (m_clearedRowsCurrentFrame != -1)
	{
		handleScore();

		m_shapeQueue.push(generateRandomShape());
		Figura nextShape = Figura(*m_shapeQueue.pop());
		m_hasGameFinished = hasToppedOut(nextShape);
		m_game.changeShape(nextShape);
	}

	if (m_time > m_timeMultiplier)
	{
		m_clearedRowsCurrentFrame = m_game.baixaFigura();
		m_time = 0.0;
	}
}

// End condition for automated games is topOut, no more shapes or no more moves
void Partida::automatedGame(double deltaTime)
{
	m_time += deltaTime;
	if (m_clearedRowsCurrentFrame != -1)
	{
		handleScore();

		if (!m_shapeQueue.isEmpty())
		{
			Figura nextShape = Figura(*m_shapeQueue.pop());
			m_hasGameFinished = hasToppedOut(nextShape);
			m_game.changeShape(nextShape);
		}
		else
			m_hasGameFinished = true;
	}

	if (m_time > m_timeMultiplier)
	{
		if (!m_movementQueue.isEmpty())
			handleNextMove(m_movementQueue.pop());
		else
			m_hasGameFinished = true;

		m_time = 0.0;
	}
}

void Partida::handleScore()
{
	static int lastIncrement = 0;

	if (m_clearedRowsCurrentFrame >= 1)
		m_score += 100;
	else
		m_score += 10;

	if (m_clearedRowsCurrentFrame == 2)
		m_score += 50;
	else if (m_clearedRowsCurrentFrame == 3)
		m_score += 75;
	else if (m_clearedRowsCurrentFrame == 4)
		m_score += 100;

	if (m_score / 1000 > lastIncrement)
	{
		++m_currentLevel;
		lastIncrement = m_score / 1000;
		m_timeMultiplier = calculateTimeMultiplier(m_timeMultiplier);
	}

	m_clearedRowsCurrentFrame = -1;
}

void Partida::handleGameInput()
{
	TipusTecla keyPressed = getKeyPressed();
	int clearedRows = 0;

	switch (keyPressed)
	{
	case TECLA_ESQUERRA:
		m_game.mouFigura(-1);
		break;

	case TECLA_DRETA:
		m_game.mouFigura(1);
		break;

	case TECLA_AMUNT:
		m_game.giraFigura(GIR_HORARI);
		break;

	case TECLA_ABAIX:
		// I prefer to make the shape go down rather thar rotate ONLY NORMAL
		// m_game.giraFigura(GIR_ANTI_HORARI);
		m_game.baixaFigura();
		break;

	case TECLA_ESPAI:
		m_clearedRowsCurrentFrame = m_game.hardDropShape();
		break;
	}
}

void Partida::handleNextMove(TipusMoviment nextMove)
{
	switch (nextMove)
	{
	case MOVIMENT_ESQUERRA:
		m_game.mouFigura(-1);
		break;

	case MOVIMENT_DRETA:
		m_game.mouFigura(1);
		break;

	case MOVIMENT_GIR_HORARI:
		m_game.giraFigura(GIR_HORARI);
		break;

	case MOVIMENT_GIR_ANTI_HORARI:
		m_game.giraFigura(GIR_ANTI_HORARI);
		break;

	case MOVIMENT_BAIXA:
		m_clearedRowsCurrentFrame = m_game.baixaFigura();
		break;

	case MOVIMENT_BAIXA_FINAL:
		m_clearedRowsCurrentFrame = m_game.hardDropShape();
		break;
	}
}

void Partida::initAutomatedGame(
	const string& fitxerInicial,
	const string& fitxerFigures,
	const string& fitxerMoviments
)
{
	m_game.inicialitza(fitxerInicial);
	m_shapeQueue = deserializeShapes(fitxerFigures);
	m_movementQueue = deserializeMoves(fitxerMoviments);
}

void Partida::initNormalGame()
{
	Figura randomShape = generateRandomShape();
	m_game.changeShape(randomShape);

	// Always 3 shapes on queue
	for (int i = 0; i < 4; i++)
	{
		Figura nextRandomShape = generateRandomShape();
		m_shapeQueue.push(nextRandomShape);
	}
}

void Partida::renderGame()
{
	// Score
	string scoreText = "SCORE: " + to_string(m_score);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 20, 20, 1, scoreText);

	// Level
	string levelText = "LEVEL: " + to_string(m_currentLevel);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 20, 60, 1, levelText);

	// Game information
	m_game.showBoard();
	//m_game.showCoordinates();

	//	Death Notification
	if (m_hasGameFinished)
	{
		// Depth effect
		GraphicManager::getInstance()->drawFont(FONT_RED_30, 35 + 4, SCREEN_SIZE_Y / 4 - 4, 2, "GAME OVER");
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 35, SCREEN_SIZE_Y / 4, 2, "GAME OVER");

		GraphicManager::getInstance()->drawFont(FONT_RED_30, 75 + 2, SCREEN_SIZE_Y - 102, 1, "PRESS ESCAPE...");

		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 75, SCREEN_SIZE_Y - 100, 1, "PRESS ESCAPE...");
	}
}

void Partida::renderNextShapes()
{
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, SCREEN_SIZE_X - 130, SCREEN_SIZE_Y / 5, 1, "NEXT");

	int lastX = SCREEN_SIZE_X - 130;
	int lastY = (SCREEN_SIZE_Y / 5) + (3 * MIDA_QUADRAT);

	const ShapeNode* currentNode = m_shapeQueue.getHead();
	for (int i = 0; i < 3; i++)
	{
		if (currentNode != nullptr)
		{
			lastY = renderShapePreview(currentNode->getShape(), lastX, lastY);
			lastY += MIDA_QUADRAT;
			currentNode = currentNode->getNextNode();
		}
	}
}

int Partida::renderShapePreview(const Figura& shape, int lastX, int lastY)
{
	IMAGE_NAME sprite = static_cast<IMAGE_NAME>(shape.getColor() + 1);
	int columns = shape.getColumns();
	int rows = shape.getRows();

	int currentX = lastX;

	for (int i = 0; i < rows; i++)
	{
		bool isDataInRow = false;

		for (int j = 0; j < columns; j++)
		{
			currentX = lastX + (j * MIDA_QUADRAT);

			if (shape.getShapeMatrix()[i][j] != COLOR_NEGRE)
			{
				isDataInRow = true;
				GraphicManager::getInstance()->drawSprite(
					sprite,
					currentX,
					lastY,
					false
				);
			}
		}

		// Grows vertically every row (that contains data)
		if (isDataInRow)
			lastY += MIDA_QUADRAT;
	}

	return lastY;
}

TipusTecla Partida::getKeyPressed()
{
	TipusTecla keyPressed;
	if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
		keyPressed = TECLA_DRETA;
	else if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
		keyPressed = TECLA_ESQUERRA;
	else if (Keyboard_GetKeyTrg(KEYBOARD_UP))
		keyPressed = TECLA_AMUNT;
	else if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
		keyPressed = TECLA_ABAIX;
	else if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
		keyPressed = TECLA_ESPAI;
	else
		keyPressed = NO_TECLA;

	return keyPressed;
}

// TOP OUT CONDITION: the shape is overlapping with another one
bool Partida::hasToppedOut(const Figura& newShape)
{
	return m_game.hasToppedOut(newShape);
}

bool Partida::hasGameFinished() const
{
	return m_hasGameFinished;
}

int Partida::getGameScore() const
{
	return m_score;
}
