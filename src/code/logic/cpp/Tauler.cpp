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
	shape.setXBoardPosition(xPos);
	shape.setYBoardPosition(yPos);

	for (int i = 0; i < shape.getRows(); ++i)
	{
		for (int j = 0; j < shape.getColumns(); ++j)
		{
			if (shapeMatrix[i][j] != 0)
			{
				int rowIndex = i + yPos;
				int columnIndex = j + xPos;

				m_board[rowIndex][columnIndex] = shape.getColor();
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

int Tauler::clearCompletedRows()
{
	int completedRowCount = 0;

	for (int i = MAX_FILA - 1; i >= 0;)
	{
		bool rowFilled = true;
		for (int j = 0; j < MAX_COL; ++j)
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

// rowIndex: the index of the row removed
void Tauler::moveRowsDown(int rowIndex)
{
	for (int k = rowIndex; k > 0; --k)
	{
		for (int l = 0; l < MAX_COL; ++l)
		{
			m_board[k][l] = m_board[k - 1][l];
		}
	}

	for (int m = 0; m < MAX_COL; ++m)
	{
		m_board[0][m] = COLOR_NEGRE;
	}
}

void Tauler::redrawShape()
{
	for (int i = 0; i < m_currentShape->getRows(); i++)
	{
		for (int j = 0; j < m_currentShape->getColumns(); ++j)
		{
			int rowIndex = i + m_currentShape->getYBoardPosition();;
			int columnIndex = j + m_currentShape->getXBoardPosition();

			if (m_currentShape->getShapeMatrix()[i][j] != COLOR_NEGRE)
				m_board[rowIndex][columnIndex] = m_currentShape->getColor();
		}
	}
}

void Tauler::clearShape()
{
	for (int i = 0; i < m_currentShape->getRows(); i++)
	{
		for (int j = 0; j < m_currentShape->getColumns(); ++j)
		{
			int rowIndex = i + m_currentShape->getYBoardPosition();
			int columnIndex = j + m_currentShape->getXBoardPosition();

			if (m_currentShape->getShapeMatrix()[i][j] != COLOR_NEGRE)
				m_board[rowIndex][columnIndex] = COLOR_NEGRE;
		}
	}
}

bool Tauler::isShapeColliding(const Figura& shape) const
{
	int** shapeMatrix = shape.getShapeMatrix();
	Tauler boardCopy = *this;
	boardCopy.clearShape();

	bool isShapeColliding = false;
	bool isShapeOutOfBounds = false;

	for (int i = 0; i < shape.getRows(); ++i)
	{
		for (int j = 0; j < shape.getColumns(); ++j)
		{
			int rowIndex = i + shape.getYBoardPosition();
			int columnIndex = j + shape.getXBoardPosition();

			// Only check where there's a tile
			if (shapeMatrix[i][j] != COLOR_NEGRE)
			{
				// Check for out of bounds
				if ((rowIndex >= MAX_FILA || rowIndex < 0) || (columnIndex >= MAX_COL || columnIndex < 0))
					isShapeOutOfBounds = true;

				// If the position in the board is occupied, there's a collision
				if (boardCopy.m_board[rowIndex][columnIndex] != COLOR_NEGRE)
					isShapeColliding = true;
			}
		}
	}

	return isShapeColliding || isShapeOutOfBounds;
}

void Tauler::showBoard()
{
/*
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
*/

	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			if (m_board[i][j] != COLOR_NEGRE)
			{
				// Convert the current color to IMAGE_NAME with an offset of 1
				IMAGE_NAME shapeType = static_cast<IMAGE_NAME>(m_board[i][j] + 1);

				// Render the sprite with the point 0 of reference on the board
				GraphicManager::getInstance()->drawSprite(
					shapeType,
					POS_X_TAULER + ((j + 1) * MIDA_QUADRAT),
					POS_Y_TAULER + (i * MIDA_QUADRAT),
					false
				);
			}
		}
	}
}