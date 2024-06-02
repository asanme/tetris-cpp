#include <fstream>
#include "headers/InfoJoc.h"
#include "headers/Figura.h"
#include "headers/Partida.h"

static Figura readShapeData(const int* shapeData)
{
	Figura currentShape;
	TipusFigura tipusFigura = static_cast<TipusFigura>(shapeData[0]);
	int yPos = shapeData[1] - 1;
	int xPos = shapeData[2] - 1;
	int rotationIndex = shapeData[3];

	currentShape.setShape(tipusFigura);
	currentShape.setYBoardPosition(yPos);
	currentShape.setXBoardPosition(xPos);

	for (int i = 0; i < rotationIndex; i++)
		currentShape.rotateShape(GIR_HORARI);

	return currentShape;
}

static ShapeQueue deserializeShapes(const string& fitxerFigures)
{
	ShapeQueue shapeQueue;
	ifstream shapesFile;

	shapesFile.open(fitxerFigures);
	if (shapesFile.is_open())
	{
		string currentLine;

		while (getline(shapesFile, currentLine))
		{
			int shapeData[4];
			deserializeShapeData(shapeData, currentLine);
			Figura currentShape = readShapeData(shapeData);
			shapeQueue.push(currentShape);
		}
	}

	shapesFile.close();
	return shapeQueue;
}

static void deserializeMoves(const string& fitxerMoviments)
{
	ifstream movesFile;

	movesFile.open(fitxerMoviments);
	if (movesFile.is_open())
	{
		char movement;
		while (movesFile >> movement)
		{
			if (isdigit(movement))
			{
				int movementValue = movement - '0';
			}
		}
	}

	movesFile.close();
}

void Partida::inicialitza(
	int mode,
	const string& fitxerInicial,
	const string& fitxerFigures,
	const string& fitxerMoviments
)
{
	m_game.inicialitza(fitxerInicial);
	m_shapeQueue = deserializeShapes(fitxerFigures);

	if (mode == AUTOMATED)
	{
		deserializeMoves(fitxerMoviments);
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
	drawBackground();

	int completedRows = -1;
	float waitTime = 0.5;
	m_time += deltaTime;
	// update(0.5, deltaTime);

	if (m_time > waitTime)
	{
		completedRows = m_game.baixaFigura();
		m_time = 0.0;
	}

	if (completedRows != -1)
		m_shapeReachedEnd = true;

	if (m_shapeReachedEnd)
	{
		//TODO Spawn new shape and reset m_shapeReachedEnd
		if (!m_shapeQueue.isEmpty())
			m_game.changeShape(Figura(*m_shapeQueue.pop()));

		GraphicManager::getInstance()->drawFont(
			FONT_WHITE_30,
			POS_X_TAULER,
			POS_Y_TAULER,
			1,
			"Ha llegado al final"
		);

		m_shapeReachedEnd = false;
	}

	m_game.showBoard();
	m_game.showCoordinates();

	handleGameInput();
}

void Partida::automatedGame(double deltaTime)
{
	drawBackground();
}

void Partida::drawBackground()
{
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
}

void Partida::handleGameInput()
{
	TipusTecla keyPressed = NO_TECLA;

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
		// TODO Add method inside Joc to drop shape to the end
		break;
	}
}
