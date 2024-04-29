#pragma once

#include "Figura.h"

class Tauler
{
 public:
	~Tauler()
	{
		m_currentShape = nullptr;
	}

	Tauler()
	{
		for (int i = 0; i < MAX_FILA; i++)
		{
			for (int j = 0; j < MAX_COL; j++)
			{
				m_board[i][j] = COLOR_NEGRE;
			}
		}
	}

	void showBoard();
	void addShape(Figura& shape);
	void updateBoard();

	int** getBoard() const;
	void setBoard(int** board);

 private:
	void updateCurrentShape();
	void clearShapePosition();

	ColorFigura m_board[MAX_FILA][MAX_COL];
	Figura* m_currentShape;
};
