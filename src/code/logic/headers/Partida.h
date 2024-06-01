#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <string>
#include "InfoJoc.h"
#include "Joc.h"

using namespace std;

typedef enum
{
	NORMAL,
	AUTOMATED
} GameMode;

class Partida
{
 public:
	Partida() : m_time(0), m_score(0), m_currentLevel(0), m_shapeReachedEnd(false)
	{
	}

	void actualitza(GameMode gameMode, double deltaTime);

	void inicialitza(
		int mode,
		const string& fitxerInicial,
		const string& fitxerFigures,
		const string& fitxerMoviments
	);

 private:
	Joc m_game;

	double m_time;
	int m_score;
	int m_currentLevel;
	bool m_shapeReachedEnd;

	// Utility methods
	void update(float waitTime, double d);
	void handleGameInput();
	static void drawBackground();

	// Other gamemodes
	void normalGame(double deltaTime);
	void automatedGame(double deltaTime);
};

#endif 
