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
	Partida() : m_temps(0), m_score(0), m_currentLevel(0)
	{
	}

	void actualitza(double d)
	{

	}

 private:
	Joc m_game;

	double m_temps;
	int m_score;
	int m_currentLevel;

};

#endif 
