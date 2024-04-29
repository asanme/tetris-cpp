#include "../headers/Figura.h"
#include <iostream>

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

}

void Figura::moveVertically()
{

}

void Figura::setShape(TipusFigura shape)
{
	if (m_shapeMatrix != nullptr)
		freeShapeMatrix();

	m_shape = shape;

	int** newMatrixShape = nullptr;
	int columns;
	int rows;

	switch (shape)
	{
	case FIGURA_O:
		rows = 2;
		columns = 2;

		newMatrixShape = new int* [rows];
		for (int i = 0; i < rows; i++)
			newMatrixShape[i] = new int[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				newMatrixShape[i][j] = 0;

		newMatrixShape[0][0] = 1;
		newMatrixShape[0][1] = 1;
		newMatrixShape[1][0] = 1;
		newMatrixShape[1][1] = 1;

		break;

	case FIGURA_I:
		rows = 4;
		columns = 4;

		newMatrixShape = new int* [rows];
		for (int i = 0; i < rows; i++)
			newMatrixShape[i] = new int[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				newMatrixShape[i][j] = 0;

		newMatrixShape[1][0] = 1;
		newMatrixShape[1][1] = 1;
		newMatrixShape[1][2] = 1;
		newMatrixShape[1][3] = 1;

		break;

	case FIGURA_T:
		rows = 3;
		columns = 3;

		newMatrixShape = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			newMatrixShape[i] = new int[columns];
		}

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				newMatrixShape[i][j] = 0;

		newMatrixShape[1][0] = 1;
		newMatrixShape[1][1] = 1;
		newMatrixShape[1][2] = 1;
		newMatrixShape[0][1] = 1;

		break;

	case FIGURA_L:
		rows = 3;
		columns = 3;

		newMatrixShape = new int* [rows];
		for (int i = 0; i < rows; i++)
			newMatrixShape[i] = new int[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				newMatrixShape[i][j] = 0;

		newMatrixShape[1][0] = 1;
		newMatrixShape[1][1] = 1;
		newMatrixShape[1][2] = 1;
		newMatrixShape[0][2] = 1;

		break;

	case FIGURA_J:
		rows = 3;
		columns = 3;

		newMatrixShape = new int* [rows];
		for (int i = 0; i < rows; i++)
			newMatrixShape[i] = new int[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				newMatrixShape[i][j] = 0;

		newMatrixShape[0][0] = 1;
		newMatrixShape[1][0] = 1;
		newMatrixShape[1][1] = 1;
		newMatrixShape[1][2] = 1;

		break;

	case FIGURA_Z:
		rows = 3;
		columns = 3;

		newMatrixShape = new int* [rows];
		for (int i = 0; i < rows; i++)
			newMatrixShape[i] = new int[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				newMatrixShape[i][j] = 0;

		newMatrixShape[0][0] = 1;
		newMatrixShape[0][1] = 1;
		newMatrixShape[1][1] = 1;
		newMatrixShape[1][2] = 1;

		break;

	case FIGURA_S:
		rows = 3;
		columns = 3;

		newMatrixShape = new int* [rows];
		for (int i = 0; i < rows; i++)
			newMatrixShape[i] = new int[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				newMatrixShape[i][j] = 0;

		newMatrixShape[0][1] = 1;
		newMatrixShape[0][2] = 1;
		newMatrixShape[1][0] = 1;
		newMatrixShape[1][1] = 1;

		break;
	}

	if (newMatrixShape != nullptr)
	{
		m_shapeMatrix = newMatrixShape;
		m_columns = columns;
		m_rows = rows;
	}
}

void Figura::showShape()
{
	if (m_shapeMatrix != nullptr)
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				cout << m_shapeMatrix[i][j] << " ";
			}

			cout << "\n";
		}
	}
}

// Frees the memory allocated in the pointer and sets the columns and rows to 0
void Figura::freeShapeMatrix()
{
	for (int i = 0; i < m_rows; i++)
	{
		delete[] m_shapeMatrix[i];
	}

	delete[] m_shapeMatrix;

	m_rows = 0;
	m_columns = 0;
	m_shapeMatrix = nullptr;
}

int** Figura::getShapeMatrix() const
{
	return m_shapeMatrix;
}

TipusFigura Figura::getShape() const
{
	return m_shape;
}

ColorFigura Figura::getColor() const
{
	return m_color;
}

void Figura::setColor(ColorFigura color)
{
	m_color = color;
}

int Figura::getXPosition() const
{
	return m_xPosition;
}

void Figura::setXPosition(int xPosition)
{
	m_xPosition = xPosition;
}

int Figura::getYPosition() const
{
	return m_yPosition;
}

void Figura::setYPosition(int yPosition)
{
	m_yPosition = yPosition;
}

int Figura::getColumns() const
{
	return m_columns;
}

int Figura::getRows() const
{
	return m_rows;
}
