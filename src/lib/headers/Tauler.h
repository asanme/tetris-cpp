#pragma once

#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
 public:
	Tauler();
 private:
	ColorFigura m_board[MAX_FILA][MAX_COL];
};
