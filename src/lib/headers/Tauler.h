#pragma once

#include "Figura.h"

class Tauler
{
 public:
	Tauler()
	{
		m_currentShape = nullptr;

		for (int i = 0; i < MAX_FILA; i++)
		{
			for (int j = 0; j < MAX_COL; j++)
			{
				m_board[i][j] = COLOR_NEGRE;
			}
		}
	}

	Tauler(const Tauler& tauler)
	{
		m_currentShape = nullptr;
		if (tauler.m_currentShape != nullptr)
		{
			m_currentShape = new Figura(*tauler.m_currentShape);
		}

		for (int i = 0; i < MAX_FILA; i++)
		{
			for (int j = 0; j < MAX_COL; ++j)
			{
				m_board[i][j] = tauler.m_board[i][j];
			}
		}
	}

	void addShape(Figura& shape, int xPos, int yPos);
	void moveShape(int xDir);
	void moveShapeVertically();
	void rotateShape(DireccioGir direction);
	int clearCompletedRows();

	bool isRotationValid(DireccioGir direction);
	bool isMovementValid(int dirX);
	bool isVerticalMovementValid();

	int** dumpBoard() const;
	void loadBoard(int** board);

	// Debug only
	void showBoard();

 private:
	bool isShapeColliding(const Figura& shape) const;
	void moveRowsDown();
	void redrawShape();
	void clearShape();

	ColorFigura m_board[MAX_FILA][MAX_COL];
	Figura* m_currentShape;
	void moveRowsDown(int rowIndex);
};
