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

	// Debug only
	void showBoard();
	void showCoordinates();

 private:
	void setGameData(int** boardMatrixData, const int* shapeData);

	Tauler m_board;
	// TODO Remove (?)
	Figura m_currentShape;
};

static void deserializeShapeData(int* shapeData, string& currentLine)
{
	int dataIndex = 0;

	for (char c : currentLine)
	{
		if (isdigit(c))
		{
			int currentValue = c - '0';
			shapeData[dataIndex] = currentValue;
			++dataIndex;
		}
	}
}
