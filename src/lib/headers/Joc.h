#pragma once

#include <iostream>
#include "Tauler.h"

using namespace std;

class Joc
{
 public:
	Joc() = default;

	void inicialitza(const string& nomFitxer);
	void escriuTauler(const string& nomFitxer);

	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();

	// Debug only
	void showBoard();

 private:
	Tauler m_board;
	Figura m_currentShape;
	void setGameData(int** boardMatrixData, const int* shapeData);
};
