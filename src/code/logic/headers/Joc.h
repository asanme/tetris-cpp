#pragma once

#include <iostream>
#include "Tauler.h"
#include "Figura.h"

using namespace std;

class Joc
{
 public:
	Joc() = default;

	void inicialitza(const string& nomFitxer);
	void escriuTauler(const string& nomFitxer);
	void changeShape(const Figura& newShape);

	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	int hardDropShape();

	void showBoard();
	bool hasToppedOut(const Figura& newShape);

	// Debug only
	void showCoordinates();

 private:
	void setGameData(int** boardMatrixData, const int* shapeData);

	Tauler m_board;
	Figura m_currentShape;
};

