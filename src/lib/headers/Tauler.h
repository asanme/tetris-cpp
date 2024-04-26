#pragma once

#include "Figura.h"


class Tauler
{
 public:
	Tauler();
	void mostrarTauler();

 private:
	ColorFigura m_board[MAX_FILA][MAX_COL];
};
