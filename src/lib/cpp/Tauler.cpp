#include "../headers/Tauler.h"
#include <iostream>

using namespace std;

// Loads the given matrix into the board
void Tauler::loadBoard(int** board)
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; ++j)
		{
			m_board[i][j] = static_cast<ColorFigura>(board[i][j]);
		}
	}
}

// Returns the matrix of the board
int** Tauler::dumpBoard() const
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
			{
				int rowIndex = i + xPositionOffset;
				int columnIndex = j + yPositionOffset;

				m_board[rowIndex][columnIndex] = shape.getColor();
				if (i == shape.getXPivotPosition() && j == shape.getYPivotPosition())
				{
					shape.setXBoardPivotPosition(columnIndex);
					shape.setYBoardPivotPosition(rowIndex);
				}
			}
		}
	}
}

void Tauler::rotateShape(DireccioGir direction)
{
	clearShape();
	m_currentShape->rotateShape(direction);
	redrawShape();
}

void Tauler::moveShape(int xDir)
{

}

void Tauler::redrawShape()
{
	int xPositionOffset = m_currentShape->getXBoardPivotPosition() - m_currentShape->getXPivotPosition();
	int yPositionOffset = m_currentShape->getYBoardPivotPosition() - m_currentShape->getYPivotPosition();

	for (int i = 0; i < m_currentShape->getRows(); i++)
	{
		for (int j = 0; j < m_currentShape->getColumns(); ++j)
		{
			int rowIndex = i + yPositionOffset;
			int columnIndex = j + xPositionOffset;

			if (m_currentShape->getShapeMatrix()[i][j] != 0)
				m_board[rowIndex][columnIndex] = m_currentShape->getColor();
		}
	}
}

void Tauler::clearShape()
{
	int xPositionOffset = m_currentShape->getXBoardPivotPosition() - m_currentShape->getXPivotPosition();
	int yPositionOffset = m_currentShape->getYBoardPivotPosition() - m_currentShape->getYPivotPosition();

	for (int i = 0; i < m_currentShape->getRows(); i++)
	{
		for (int j = 0; j < m_currentShape->getColumns(); ++j)
		{
			int rowIndex = i + yPositionOffset;
			int columnIndex = j + xPositionOffset;

			if (m_currentShape->getShapeMatrix()[i][j] != 0)
				m_board[rowIndex][columnIndex] = COLOR_NEGRE;
		}
	}
}

bool Tauler::isRotationValid(DireccioGir direction)
{
	Figura shapeCopy = *m_currentShape;
	shapeCopy.rotateShape(direction);
	return !isShapeColliding(shapeCopy);
}

bool Tauler::isMovementValid(int xDir)
{
	return false;
}

// TODO Add out of bounds collision check
bool Tauler::isShapeColliding(const Figura& shape) const
{
	int** shapeMatrix = shape.getShapeMatrix();
	bool doesShapeCollide = false;
	Tauler boardCopy = *this;
	boardCopy.clearShape();

	int xPositionOffset = m_currentShape->getXBoardPivotPosition() - m_currentShape->getXPivotPosition();
	int yPositionOffset = m_currentShape->getYBoardPivotPosition() - m_currentShape->getYPivotPosition();

	for (int i = 0; i < shape.getRows(); ++i)
	{
		for (int j = 0; j < shape.getColumns(); ++j)
		{
			int rowIndex = i + yPositionOffset;
			int columnIndex = j + xPositionOffset;

			// If the position in the board is occupied, there's a collision
			if (shapeMatrix[i][j] != 0 && boardCopy.m_board[rowIndex][columnIndex] != 0)
				doesShapeCollide = true;
		}
	}

	return doesShapeCollide;
}

void Tauler::showBoard()
{
	cout << "\nShowing current board:\n";
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
