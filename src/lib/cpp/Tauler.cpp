#include "../headers/Tauler.h"
#include <iostream>

using namespace std;

// TODO Check if init is valid
Tauler::Tauler()
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			m_board[i][j] = COLOR_NEGRE;
		}
	}
}

void Tauler::mostrarTauler()
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			cout << " " << m_board[i][j];
		}

		cout << "\n";
	}
}
