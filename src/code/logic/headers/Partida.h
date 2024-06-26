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
	Partida()
	{
		m_time = 0;
		m_score = 0;
		m_currentLevel = 1;
		m_timeMultiplier = 1;
		m_clearedRowsCurrentFrame = -1;
		m_hasGameFinished = false;
	}

	void actualitza(GameMode gameMode, double deltaTime);

	void inicialitza(
		GameMode gameMode,
		const string& fitxerInicial,
		const string& fitxerFigures,
		const string& fitxerMoviments
	);

	bool hasGameFinished() const;
	int getGameScore() const;

 private:
	Joc m_game;

	// Current game information
	int m_score;
	int m_currentLevel;
	int m_clearedRowsCurrentFrame;

	// Time
	double m_time;
	double m_timeMultiplier;

	// Other information
	bool m_hasGameFinished;
	ShapeQueue m_shapeQueue;
	MovementQueue m_movementQueue;

	// Util methods
	void renderGame();
	void renderNextShapes();
	static int renderShapePreview(const Figura& shape, int lastX, int lastY) ;
	bool hasToppedOut(const Figura& newShape);
	void initNormalGame();
	void initAutomatedGame(const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);

	// Event handlers
	void handleScore();
	void handleGameInput();
	void handleNextMove(TipusMoviment nextMove);

	// Keyboard handle
	static TipusTecla getKeyPressed();

	// Other game modes
	void normalGame(double deltaTime);
	void automatedGame(double deltaTime);
	void renderBackground() const;
};
