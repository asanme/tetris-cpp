#include "../headers/Tauler.h"

// TODO Check if init is valid
Tauler::Tauler()
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			m_board[i][j] = NO_COLOR;
		}
	}
}
