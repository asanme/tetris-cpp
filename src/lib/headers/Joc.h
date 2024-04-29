#pragma once

#include <iostream>
#include "Tauler.h"

using namespace std;

class Joc
{
 public:
	~Joc()
	{
		m_board = nullptr;
		m_currentShape = nullptr;
	}

	Joc()
	{
		m_board = new Tauler();
		// TODO Remove this, only for testing
		m_currentShape = new Figura();
	}

	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);

	void showBoard();

 private:
	Tauler* m_board;
	Figura* m_currentShape;
};
