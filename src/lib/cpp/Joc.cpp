#include <fstream>
#include "../headers/Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
	// TODO Reads a file and loads the information onto the board
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream file;
	file.open(nomFitxer, ios::out);

	if (file.is_open())
	{
		int** tmpBoard = m_board->getBoard();
		for (int i = 0; i < MAX_FILA; i++)
		{
			for (int j = 0; j < MAX_COL; ++j)
			{
				file << tmpBoard[i][j] << " ";
			}
			file << "\n";
		}
	}

	file.close();
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
