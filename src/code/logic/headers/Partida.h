#pragma once

#include <iostream>
#include <string>
#include "InfoJoc.h"
#include "Joc.h"
#include "../../util/headers/ShapeQueue.h"
#include "../../util/headers/MovementQueue.h"

using namespace std;

typedef enum
{
	NORMAL,
	AUTOMATED
} GameMode;

class Partida
{
 public:
	Partida() : m_time(0), m_score(0), m_currentLevel(1), m_timeMultiplier(1), m_clearedRowsCurrentFrame(-1)
	{
	}

	void actualitza(GameMode gameMode, double deltaTime);

	void inicialitza(
		GameMode gameMode,
		const string& fitxerInicial,
		const string& fitxerFigures,
		const string& fitxerMoviments
	);

 private:
	Joc m_game;

	// Current game information
	double m_time;
	int m_score;
	int m_currentLevel;
	int m_clearedRowsCurrentFrame;
	// Double for more accuracy
	double m_timeMultiplier;

	// Other information
	ShapeQueue m_shapeQueue;
	MovementQueue m_movementQueue;

	// Util methods
	void drawGame();

	// Event handlers
	void handleScore();
	void handleGameInput();
	void handleNextMove(TipusMoviment nextMove);

	// Keyboard handle
	static TipusTecla getKeyPressed();

	// Other game modes
	void normalGame(double deltaTime);
	void automatedGame(double deltaTime);
	void initAutomatedGame(const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
	void initNormalGame();
};
