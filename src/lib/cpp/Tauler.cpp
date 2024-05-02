#include "../headers/Tauler.h"
#include <iostream>

using namespace std;

void Tauler::showBoard()
{
	cout << "---------------\n";
	cout << "Showing current board:\n";
	cout << "---------------\n";

	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			cout << m_board[i][j] << " ";
		}

		cout << "\n";
	}
}

void Tauler::updateCurrentShape()
{
	// TODO
	for (int i = 0; i < m_currentShape->getRows(); i++)
	{
		for (int j = 0; j < m_currentShape->getColumns(); ++j)
		{
			int rowPosition = i + m_currentShape->getXBoardPosition();
			int columnPosition = j + m_currentShape->getYBoardPosition();

			if (m_currentShape->getShapeMatrix()[i][j] != 0)
				m_board[rowPosition][columnPosition] = m_currentShape->getColor();
		}
	}
}

void Tauler::clearShapePosition()
{
	// TODO
	for (int i = 0; i < m_currentShape->getRows(); i++)
	{
		for (int j = 0; j < m_currentShape->getColumns(); ++j)
		{
			int rowPosition = i + m_currentShape->getXBoardPosition();
			int columnPosition = j + m_currentShape->getYBoardPosition();

			if (m_currentShape->getShapeMatrix()[i][j] != 0)
				m_board[rowPosition][columnPosition] = COLOR_NEGRE;
		}
	}
}

void Tauler::addShape(Figura& shape, int xPos, int yPos)
{
	m_currentShape = &shape;
	int** shapeMatrix = shape.getShapeMatrix();
	int xPositionOffset = xPos - shape.getXPivotPosition();
	int yPositionOffset = yPos - shape.getYPivotPosition();

	for (int i = 0; i < shape.getRows(); ++i)
	{
		for (int j = 0; j < shape.getColumns(); ++j)
		{
			if (shapeMatrix[i][j] != 0)
				m_board[i + xPositionOffset][j + yPositionOffset] = shape.getColor();
		}
	}


//	updateCurrentShape();
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
			m_board[i][j] = static_cast<ColorFigura>(board[i][j]);
		}
	}
}
