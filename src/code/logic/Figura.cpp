#include <iostream>
#include "headers/Figura.h"

using namespace std;

static void invertRows(int** matrix, int rows, int columns)
{
	for (int j = 0; j < columns; ++j)
	{
		for (int i = 0; i < rows / 2; ++i)
		{
			int tmp = matrix[i][j];
			int rowIndex = rows - 1 - i;
			matrix[i][j] = matrix[rowIndex][j];
			matrix[rowIndex][j] = tmp;
		}
	}
}

static void invertColumns(int** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns / 2; ++j)
		{
			int tmp = matrix[i][j];
			int columnIndex = columns - 1 - j;
			matrix[i][j] = matrix[i][columnIndex];
			matrix[i][columnIndex] = tmp;
		}
	}
}

static void transposeMatrix(int** matrix, int rows, int columns)
{
	int matrixCopy[rows][columns];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrixCopy[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = matrixCopy[j][i];
		}
	}
}

static int** initNewMatrix(int columns, int rows)
{
	int** newMatrix = new int* [rows];

	for (int i = 0; i < rows; i++)
		newMatrix[i] = new int[columns];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			newMatrix[i][j] = 0;

	return newMatrix;
}

void Figura::rotateShape(DireccioGir rotationDirection)
{
	switch (rotationDirection)
	{
	case GIR_HORARI:
		rotateShapeClockwise();
		break;
	case GIR_ANTI_HORARI:
		rotateShapeCounterclockwise();
		break;
	}
}

void Figura::moveHorizontally(int xDirection)
{
	m_xBoardPosition += xDirection;
}

void Figura::moveVertically()
{
	++m_yBoardPosition;
}

void Figura::setShape(TipusFigura shape)
{
	if (m_shapeMatrix != nullptr)
		freeShapeMatrix();

	if (shape == NO_FIGURA)
		return;

	ColorFigura color;
	int** newMatrixShape = nullptr;
	int rows;
	int columns;

	switch (shape)
	{
	case FIGURA_O:
		color = COLOR_GROC;
		rows = 2;
		columns = 2;
		newMatrixShape = initNewMatrix(columns, rows);

		newMatrixShape[0][0] = 1;
		newMatrixShape[0][1] = 1;
		newMatrixShape[1][0] = 1;
		newMatrixShape[1][1] = 1;
		break;

	case FIGURA_I:
		color = COLOR_BLAUCEL;
		rows = 4;
		columns = 4;
		newMatrixShape = initNewMatrix(columns, rows);

		newMatrixShape[1][0] = 1;
		newMatrixShape[1][1] = 1;
		newMatrixShape[1][2] = 1;
		newMatrixShape[1][3] = 1;
		break;

	case FIGURA_T:
		color = COLOR_MAGENTA;
		rows = 3;
		columns = 3;
		newMatrixShape = initNewMatrix(columns, rows);

		newMatrixShape[1][0] = 1;
		newMatrixShape[1][1] = 1;
		newMatrixShape[1][2] = 1;
		newMatrixShape[0][1] = 1;
		break;

	case FIGURA_L:
		color = COLOR_TARONJA;
		rows = 3;
		columns = 3;
		newMatrixShape = initNewMatrix(columns, rows);

		newMatrixShape[1][0] = 1;
		newMatrixShape[1][1] = 1;
		newMatrixShape[1][2] = 1;
		newMatrixShape[0][2] = 1;
		break;

	case FIGURA_J:
		color = COLOR_BLAUFOSC;
		rows = 3;
		columns = 3;
		newMatrixShape = initNewMatrix(columns, rows);

		newMatrixShape[0][0] = 1;
		newMatrixShape[1][0] = 1;
		newMatrixShape[1][1] = 1;
		newMatrixShape[1][2] = 1;
		break;

	case FIGURA_Z:
		color = COLOR_VERMELL;
		rows = 3;
		columns = 3;
		newMatrixShape = initNewMatrix(columns, rows);

		newMatrixShape[0][0] = 1;
		newMatrixShape[0][1] = 1;
		newMatrixShape[1][1] = 1;
		newMatrixShape[1][2] = 1;
		break;

	case FIGURA_S:
		color = COLOR_VERD;
		rows = 3;
		columns = 3;
		newMatrixShape = initNewMatrix(columns, rows);

		newMatrixShape[0][1] = 1;
		newMatrixShape[0][2] = 1;
		newMatrixShape[1][0] = 1;
		newMatrixShape[1][1] = 1;
		break;
	}

	m_shape = shape;
	m_color = color;
	m_shapeMatrix = newMatrixShape;
	m_rows = rows;
	m_columns = columns;
}

int** Figura::getShapeMatrix() const
{
	return m_shapeMatrix;
}

int Figura::getColumns() const
{
	return m_columns;
}

int Figura::getRows() const
{
	return m_rows;
}

ColorFigura Figura::getColor() const
{
	return m_color;
}

int Figura::getXBoardPosition() const
{
	return m_xBoardPosition;
}

void Figura::setXBoardPosition(int xPosition)
{
	m_xBoardPosition = xPosition;
}

int Figura::getYBoardPosition() const
{
	return m_yBoardPosition;
}

void Figura::setYBoardPosition(int yPosition)
{
	m_yBoardPosition = yPosition;
}

void Figura::rotateShapeClockwise()
{
	transposeMatrix(m_shapeMatrix, m_rows, m_columns);
	invertColumns(m_shapeMatrix, m_rows, m_columns);
}

void Figura::rotateShapeCounterclockwise()
{
	transposeMatrix(m_shapeMatrix, m_rows, m_columns);
	invertRows(m_shapeMatrix, m_rows, m_columns);
}

// Frees the memory allocated in the shape
void Figura::freeShapeMatrix()
{
	if (m_shapeMatrix == nullptr)
		return;

	for (int i = 0; i < m_rows; i++)
	{
		delete[] m_shapeMatrix[i];
	}

	delete[] m_shapeMatrix;

	m_shapeMatrix = nullptr;
	m_columns = 0;
	m_rows = 0;
}

void Figura::showShape()
{
	cout << "\nShowing current shape:\n";
	cout << "---------------\n";

	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			cout << m_shapeMatrix[i][j] << " ";
		}

		cout << "\n";
	}
}
