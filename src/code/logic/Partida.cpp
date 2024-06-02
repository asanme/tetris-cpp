#include <fstream>
#include "headers/InfoJoc.h"
#include "headers/Figura.h"
#include "headers/Partida.h"
#include "../util/headers/Utilities.h"

void Partida::inicialitza(
	int mode,
	const string& fitxerInicial,
	const string& fitxerFigures,
	const string& fitxerMoviments
)
{
	m_game.inicialitza(fitxerInicial);

	if (mode == AUTOMATED)
	{
		m_shapeQueue = deserializeShapes(fitxerFigures);
		m_movementQueue = deserializeMoves(fitxerMoviments);
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

	int completedRows = -1;
	float waitTime = 0.5;
	m_time += deltaTime;

	if (m_time > waitTime)
	{
		completedRows = m_game.baixaFigura();
		m_time = 0.0;
	}

	if (completedRows != -1)
		m_shapeReachedEnd = true;

	if (m_shapeReachedEnd)
	{
		if (!m_shapeQueue.isEmpty())
		{
			Figura nextShape = Figura(*m_shapeQueue.pop());
			m_game.changeShape(nextShape);
		}

		m_shapeReachedEnd = false;
	}
}

// TODO Fix bug, the tile render doesn't match the state of the board nor current shape
void Partida::automatedGame(double deltaTime)
{
	drawGame();

	float waitTime = 0.5;
	m_time += deltaTime;

	if (m_time > waitTime)
	{
		if (!m_movementQueue.isEmpty())
			handleNextMove(m_movementQueue.pop());

		m_time = 0.0;
	}

	if (m_shapeReachedEnd)
	{
		if (!m_shapeQueue.isEmpty())
		{
			Figura nextShape = Figura(*m_shapeQueue.pop());
			m_game.changeShape(nextShape);
		}

		m_shapeReachedEnd = false;
	}
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
		if (m_game.hardDropShape() != -1)
			m_shapeReachedEnd = true;
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
		if (m_game.baixaFigura() != -1)
			m_shapeReachedEnd = true;
		break;

	case MOVIMENT_BAIXA_FINAL:
		if (m_game.hardDropShape() != -1)
			m_shapeReachedEnd = true;
		break;
	}
}

void Partida::drawGame()
{
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
	m_game.showBoard();
	m_game.showCoordinates();
}
