#include <fstream>
#include <vector>
#include "../headers/Joc.h"

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

static void deserializeMatrixData(int** tmpBoardMatrix, int& rowIndex, const string& currentLine)
{
	int matrixColumnIndex = 0;
	for (char c : currentLine)
	{
		if (isdigit(c))
		{
			int currentMatrixValue = c - '0';
			tmpBoardMatrix[rowIndex][matrixColumnIndex] = currentMatrixValue;
			++matrixColumnIndex;
		}
	}

	++rowIndex;
}

// Loads deserialized data into the objects
void Joc::setGameData(int** boardMatrixData, const int* shapeData)
{
	int row = shapeData[1];
	int column = shapeData[2];
	int rotationIndex = shapeData[3];
	m_currentShape.setShape(static_cast<TipusFigura>(shapeData[0]));

	for (int i = 0; i < rotationIndex; i++)
		m_currentShape.rotateShape(GIR_HORARI);

	m_board.loadBoard(boardMatrixData);
	m_board.addShape(m_currentShape, row, column);
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

bool Joc::giraFigura(DireccioGir direccio)
{
	return false;
}

bool Joc::mouFigura(int dirX)
{
	// TODO
	return false;
}

int Joc::baixaFigura()
{
	// TODO
	return 0;
}

void Joc::showBoard()
{
	m_board.showBoard();
}
