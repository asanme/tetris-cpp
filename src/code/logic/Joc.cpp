#include <fstream>
#include <vector>
#include "headers/Joc.h"
#include "headers/GraphicManager.h"
#include "headers/InfoJoc.h"
#include "../util/headers/Utilities.h"

void Joc::setGameData(int** boardMatrixData, const int* shapeData)
{
	int row = shapeData[1];
	int column = shapeData[2];
	int rotationIndex = shapeData[3];
	m_currentShape.setShape(static_cast<TipusFigura>(shapeData[0]));
	m_currentShape.setXBoardPosition(column - 1);
	m_currentShape.setYBoardPosition(row - 1);

	for (int i = 0; i < rotationIndex; i++)
		m_currentShape.rotateShape(GIR_HORARI);

	m_board.loadBoard(boardMatrixData);
	m_board.addShape(m_currentShape);
}

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream boardData;
	boardData.open(nomFitxer, ios::in);

	if (boardData.is_open())
	{
		string currentLine;
		int shapeData[4];
		int fileRowIndex = 0;
		int matrixRowIndex = 0;
		int** tmpBoardMatrix = new int* [MAX_FILA];

		for (int i = 0; i < MAX_FILA; i++)
			tmpBoardMatrix[i] = new int[MAX_COL];

		while (getline(boardData, currentLine))
		{
			if (fileRowIndex != 0)
				deserializeMatrixData(tmpBoardMatrix, matrixRowIndex, currentLine);
			else
				deserializeShapeData(shapeData, currentLine);

			++fileRowIndex;
		}

		setGameData(tmpBoardMatrix, shapeData);
	}

	boardData.close();
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream boardOutput;
	boardOutput.open(nomFitxer, ios::out);

	if (boardOutput.is_open())
	{
		int** tmpBoard = m_board.dumpBoard();

		for (int i = 0; i < MAX_FILA; i++)
		{
			for (int j = 0; j < MAX_COL; ++j)
			{
				boardOutput << tmpBoard[i][j] << " ";
			}
			boardOutput << "\n";
		}
	}

	boardOutput.close();
}

void Joc::changeShape(const Figura& newShape)
{
	m_currentShape = *new Figura(newShape);
	m_board.setShape(m_currentShape);
}

bool Joc::giraFigura(DireccioGir direccio)
{
	bool isRotationValid = m_board.isRotationValid(direccio);

	if (isRotationValid)
		m_board.rotateShape(direccio);

	return isRotationValid;
}

bool Joc::mouFigura(int dirX)
{
	bool isMovementValid = m_board.isHorizontalMovementValid(dirX);

	if (isMovementValid)
		m_board.moveShapeHorizontally(dirX);

	return isMovementValid;
}

int Joc::baixaFigura()
{
	bool isVerticalMovementValid = m_board.isVerticalMovementValid();
	int completedRows = -1;

	if (isVerticalMovementValid)
		m_board.moveShapeVertically();
	else
		completedRows = m_board.clearCompletedRows();

	return completedRows;
}

int Joc::hardDropShape()
{
	int totalCompletedRows = 0;
	bool hasReachedEnd = false;

	while (!hasReachedEnd)
	{
		int completedRows = baixaFigura();
		if (completedRows != -1)
		{
			hasReachedEnd = true;
			totalCompletedRows += completedRows;
		}
	}

	return totalCompletedRows;
}

void Joc::showBoard()
{
	m_board.showBoard();
}

// Debug only
void Joc::showCoordinates()
{
	string xPos = "X: " + to_string(m_currentShape.getXBoardPosition());
	string yPos = "Y: " + to_string(m_currentShape.getYBoardPosition());
	string coords = xPos + " " + yPos;

	GraphicManager::getInstance()->drawFont(
		FONT_WHITE_30,
		20,
		60,
		1,
		coords
	);
}

bool Joc::hasToppedOut(const Figura& newShape)
{
	return m_board.isShapeOverlapping(newShape);
}
