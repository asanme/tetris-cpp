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

	void addShape(Figura& shape);
	void setShape(Figura& shape);

	void moveShapeVertically();
	void moveShapeHorizontally(int xDir);
	void rotateShape(DireccioGir direction);

	int clearCompletedRows();

	bool isVerticalMovementValid();
	bool isHorizontalMovementValid(int dirX);
	bool isRotationValid(DireccioGir direction);

	int** dumpBoard() const;
	void loadBoard(int** board);

	void showBoard();

	// TODO Check if is valid
	bool isShapeOverlapping(const Figura& shape);

 private:
	bool isShapeColliding(const Figura& shape) const;
	void moveRowsDown(int rowIndex);
	void redrawShape();
	void clearShape();

	Figura* m_currentShape;
	ColorFigura m_board[MAX_FILA][MAX_COL];
};
