#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <string>
#include "InfoJoc.h"
#include "Joc.h"

using namespace std;

class Partida
{
 public:
	Partida() : m_time(0), m_score(0), m_currentLevel(0)
	{
	}

	void actualitza(double deltaTime);

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

	// Utility methods
	void update(float waitTime, double d);
};

#endif 
