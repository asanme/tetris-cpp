#include "../headers/Tauler.h"
#include <iostream>

using namespace std;

void Tauler::showBoard()
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

void Tauler::updateCurrentShape()
{
	for (int i = 0; i < m_currentShape->getRows(); i++)
	{
		for (int j = 0; j < m_currentShape->getColumns(); ++j)
		{
			int rowPosition = i + m_currentShape->getXPosition();
			int columnPosition = j + m_currentShape->getYPosition();

			if (m_currentShape->getShapeMatrix()[i][j] != 0)
				m_board[rowPosition][columnPosition] = m_currentShape->getColor();
		}
	}
}

void Tauler::clearShapePosition()
{
	for (int i = 0; i < m_currentShape->getRows(); i++)
	{
		for (int j = 0; j < m_currentShape->getColumns(); ++j)
		{
			int rowPosition = i + m_currentShape->getXPosition();
			int columnPosition = j + m_currentShape->getYPosition();

			if (m_currentShape->getShapeMatrix()[i][j] != 0)
				m_board[rowPosition][columnPosition] = COLOR_NEGRE;
		}
	}
}

void Tauler::addShape(Figura& shape)
{
	m_currentShape = &shape;
	updateCurrentShape();
}

void Tauler::updateBoard()
{
	if (m_currentShape == nullptr)
		return;

	clearShapePosition();
	updateCurrentShape();
}

int** Tauler::getBoard() const
{
	int** boardMatrix = new int* [MAX_FILA];
	for (int i = 0; i < MAX_FILA; i++)
		boardMatrix[i] = new int[MAX_COL];

	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			boardMatrix[i][j] = m_board[i][j];
		}
	}

	return boardMatrix;
}
void Tauler::setBoard(int** board)
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; ++j)
		{
			// TODO Remove static cast and add a switch instead
			m_board[i][j] = static_cast<ColorFigura>(board[i][j]);
		}
	}
}
