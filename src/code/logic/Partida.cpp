#include <fstream>
#include "headers/InfoJoc.h"
#include "headers/Figura.h"
#include "headers/Partida.h"
#include "../util/headers/Utilities.h"

void Partida::initAutomatedGame(const string& fitxerInicial,
	const string& fitxerFigures,
	const string& fitxerMoviments)
{
	m_game.inicialitza(fitxerInicial);
	m_shapeQueue = deserializeShapes(fitxerFigures);
	m_movementQueue = deserializeMoves(fitxerMoviments);
}

void Partida::initNormalGame()
{
	Figura randomShape = generateRandomShape();
	m_game.changeShape(randomShape);
}

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

void Partida::normalGame(double deltaTime)
{
	drawGame();
	handleGameInput();

	float waitTime = 0.5;
	m_time += deltaTime;
	if (m_clearedRowsCurrentFrame != -1)
	{
		handleScore();
		Figura nextShape = generateRandomShape();
		m_game.changeShape(nextShape);
	}

	if (m_time > waitTime)
	{
		m_clearedRowsCurrentFrame = m_game.baixaFigura();
		m_time = 0.0;
	}
}

void Partida::automatedGame(double deltaTime)
{
	drawGame();

	float waitTime = 0.5;
	m_time += deltaTime;
	if (m_clearedRowsCurrentFrame != -1)
	{
		handleScore();

		if (!m_shapeQueue.isEmpty())
		{
			Figura nextShape = Figura(*m_shapeQueue.pop());
			m_game.changeShape(nextShape);
		}
	}

	if (m_time > waitTime)
	{
		if (!m_movementQueue.isEmpty())
			handleNextMove(m_movementQueue.pop());

		m_time = 0.0;
	}
}

void Partida::handleScore()
{
	static int lastIncrement = 0;
	m_score += 10;

	if (m_clearedRowsCurrentFrame >= 1)
		m_score += 100;

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
		m_game.giraFigura(GIR_ANTI_HORARI);
		break;

	case TECLA_ESPAI:
		m_clearedRowsCurrentFrame = m_game.hardDropShape();
		break;
	}
}

void Partida::handleNextMove(TipusMoviment nextMove)
{
	int clearedRows = 0;
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

void Partida::drawGame()
{
	// Background
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);

	// Score
	string scoreText = "SCORE: " + to_string(m_score);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 20, 20, 1, scoreText);

	// Score
	string levelText = "LEVEL: " + to_string(m_currentLevel);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 20, 60, 1, levelText);

	// Game information
	m_game.showBoard();
//	m_game.showCoordinates();
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
