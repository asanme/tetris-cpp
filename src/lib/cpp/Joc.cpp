#include <fstream>
#include <vector>
#include "../headers/Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream boardData;
	boardData.open(nomFitxer, ios::in);

	if (boardData.is_open())
	{
		string currentLine;
		while (getline(boardData, currentLine))
		{
			std::cout << currentLine << "\n";
		}
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
