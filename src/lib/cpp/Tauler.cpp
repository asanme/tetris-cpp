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

				if ((rowIndex >= MAX_FILA || rowIndex < 0) || (columnIndex >= MAX_COL || columnIndex < 0))
					return;

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
	clearShape();
	m_currentShape->moveHorizontally(xDir);
	redrawShape();
}

void Tauler::moveShapeVertically()
{
	clearShape();
	m_currentShape->moveVertically();
	redrawShape();
}

void Tauler::redrawShape()
{
	int xPositionOffset = m_currentShape->getXBoardPivotPosition() - m_currentShape->getXPivotPosition();
	int yPositionOffset = m_currentShape->getYBoardPivotPosition() - m_currentShape->getYPivotPosition();

	int rows = m_currentShape->getRows();
	int columns = m_currentShape->getColumns();
	ColorFigura color = m_currentShape->getColor();
	int** shapeMatrix = m_currentShape->getShapeMatrix();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; ++j)
		{
			int rowIndex = i + yPositionOffset;
			int columnIndex = j + xPositionOffset;

			if (shapeMatrix[i][j] != 0)
				m_board[rowIndex][columnIndex] = color;
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
	Figura shapeCopy = *m_currentShape;
	shapeCopy.moveHorizontally(xDir);
	return !isShapeColliding(shapeCopy);
}

bool Tauler::isVerticalMovementValid()
{
	Figura shapeCopy = *m_currentShape;
	shapeCopy.moveVertically();
	return !isShapeColliding(shapeCopy);
}

bool Tauler::isShapeColliding(const Figura& shape) const
{
	int** shapeMatrix = shape.getShapeMatrix();
	Tauler boardCopy = *this;
	boardCopy.clearShape();

	bool doesShapeCollide = false;
	bool isShapeOutOfBounds = false;
	int xPositionOffset = shape.getXBoardPivotPosition() - shape.getXPivotPosition();
	int yPositionOffset = shape.getYBoardPivotPosition() - shape.getYPivotPosition();
	for (int i = 0; i < shape.getRows(); ++i)
	{
		for (int j = 0; j < shape.getColumns(); ++j)
		{
			int rowIndex = i + yPositionOffset;
			int columnIndex = j + xPositionOffset;

			// Only check where there's a tile
			if (shapeMatrix[i][j] != 0)
			{
				if ((rowIndex >= MAX_FILA || rowIndex < 0) || (columnIndex >= MAX_COL || columnIndex < 0))
					isShapeOutOfBounds = true;

				// If the position in the board is occupied, there's a collision
				if (boardCopy.m_board[rowIndex][columnIndex] != 0)
					doesShapeCollide = true;
			}
		}
	}

	return doesShapeCollide || isShapeOutOfBounds;
}

int Tauler::clearCompletedRows()
{
	int completedRowCount = 0;
	for (int i = 7; i >= 0;)
	{
		bool rowFilled = true;
		for (int j = 0; j < 8; ++j)
		{
			if (m_board[i][j] == COLOR_NEGRE)
			{
				rowFilled = false;
				break;
			}
		}
		if (rowFilled)
		{
			moveRowsDown(i);
			++completedRowCount;
		}
		else
		{
			--i;
		}
	}

	return completedRowCount;
}

void Tauler::moveRowsDown(int rowIndex)
{
	for (int k = rowIndex; k > 0; --k)
	{
		for (int l = 0; l < 8; ++l)
		{
			m_board[k][l] = m_board[k - 1][l];
		}
	}

	for (int m = 0; m < 8; ++m)
	{
		m_board[0][m] = COLOR_NEGRE;
	}
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
