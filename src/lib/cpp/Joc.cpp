#include <fstream>
#include <vector>
#include "../headers/Joc.h"

static void extractShapeData(string& currentLine, int* shapeData)
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

		cout << c << " ";
	}

	cout << "\n";
}

static void extractMatrixData(int** tmpBoardMatrix, const string& currentLine, int& rowIndex)
{
	int matrixColumnIndex = 0;
	for (int i = 0; i < currentLine.length(); i++)
	{
		if (isdigit(currentLine[i]))
		{
			int currentMatrixValue = currentLine[i] - '0';
			tmpBoardMatrix[rowIndex][matrixColumnIndex] = currentMatrixValue;
			++matrixColumnIndex;
		}
	}

	++rowIndex;
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
			{
				extractMatrixData(tmpBoardMatrix, currentLine, matrixRowIndex);
			}
			else
			{
				extractShapeData(currentLine, shapeData);
			}

			++fileRowIndex;
		}

		// TODO Remove static cast
		Figura f;
		int row = shapeData[1];
		int column = shapeData[2];
		int rotationIndex = shapeData[3];
		f.setShape(static_cast<TipusFigura>(shapeData[0]));
		for (int i = 0; i < rotationIndex; i++)
		{
			f.rotateShape(GIR_HORARI);
		}

		f.showShape();

		m_board->setBoard(tmpBoardMatrix);
	}

	boardData.close();
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream boardOutput;
	boardOutput.open(nomFitxer, ios::out);

	if (boardOutput.is_open())
	{
		int** tmpBoard = m_board->getBoard();
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
	m_currentShape->moveHorizontally(dirX);
	return false;
}

int Joc::baixaFigura()
{
	m_currentShape->moveVertically();
	return 0;
}

void Joc::showBoard()
{
	m_board->showBoard();
}
