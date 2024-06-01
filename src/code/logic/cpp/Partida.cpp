#include <fstream>
#include "../headers/Partida.h"
#include "../headers/InfoJoc.h"
#include "../headers/GraphicManager.h"

static void deserializeShapes(const string& fitxerFigures)
{
	ifstream shapesFile;

	shapesFile.open(fitxerFigures);
	if (shapesFile.is_open())
	{
		string currentLine;

		while (getline(shapesFile, currentLine))
		{
			int currentShape[4];
			deserializeShapeData(currentShape, currentLine);
		}
	}

	shapesFile.close();
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
	const string& fitxerMoviments)
{
	m_game.inicialitza(fitxerInicial);

	if (mode == AUTOMATED)
	{
		deserializeShapes(fitxerFigures);
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
		GraphicManager::getInstance()->drawFont(
			FONT_WHITE_30,
			POS_X_TAULER,
			POS_Y_TAULER,
			1,
			"Ha llegado al final"
		);
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
