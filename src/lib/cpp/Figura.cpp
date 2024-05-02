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

	if (m_shape == FIGURA_I)
	{
		if (m_rotationIndex == 3)
			m_rotationIndex = 0;
		else
			++m_rotationIndex;

		switch (m_rotationIndex)
		{
		case ROTATION_UP:
			m_xPivotPosition = 2;
			m_yPivotPosition = 1;
			break;

		case ROTATION_RIGHT:
			m_xPivotPosition = 2;
			m_yPivotPosition = 2;
			break;

		case ROTATION_DOWN:
			m_xPivotPosition = 1;
			m_yPivotPosition = 2;
			break;

		case ROTATION_LEFT:
			m_xPivotPosition = 1;
			m_yPivotPosition = 1;
			break;
		}
	}
}

void Figura::rotateShapeCounterclockwise()
{
	transposeMatrix(m_shapeMatrix, m_rows, m_columns);
	invertRows(m_shapeMatrix, m_rows, m_columns);

	// TODO Implement the rest of pivot rotations for FIGURA_I
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
	// TODO
}

void Figura::moveVertically()
{
	// TODO
}

void Figura::setShape(TipusFigura shape)
{
	if (m_shapeMatrix != nullptr)
		freeShapeMatrix();

	int** newMatrixShape = nullptr;
	ColorFigura color;
	int columns;
	int rows;

	switch (shape)
	{
	case FIGURA_O:
		rows = 2;
		columns = 2;
		color = COLOR_GROC;

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
		color = COLOR_BLAUCEL;

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

		m_xPivotPosition = 2;
		m_yPivotPosition = 1;

		break;

	case FIGURA_T:
		rows = 3;
		columns = 3;
		color = COLOR_MAGENTA;

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

		m_xPivotPosition = 1;
		m_yPivotPosition = 1;

		break;

	case FIGURA_L:
		rows = 3;
		columns = 3;
		color = COLOR_TARONJA;

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

		m_xPivotPosition = 1;
		m_yPivotPosition = 1;

		break;

	case FIGURA_J:
		rows = 3;
		columns = 3;
		color = COLOR_BLAUFOSC;

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

		m_xPivotPosition = 1;
		m_yPivotPosition = 1;

		break;

	case FIGURA_Z:
		rows = 3;
		columns = 3;
		color = COLOR_VERMELL;

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

		m_xPivotPosition = 1;
		m_yPivotPosition = 1;

		break;

	case FIGURA_S:
		rows = 3;
		columns = 3;
		color = COLOR_VERD;

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

		m_xPivotPosition = 1;
		m_yPivotPosition = 1;

		break;
	}

	// If TipusFigura is not NO_FIGURA
	if (newMatrixShape != nullptr)
	{
		m_shapeMatrix = newMatrixShape;
		m_columns = columns;
		m_rows = rows;

		m_shape = shape;
		m_color = color;
	}
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

	m_rows = 0;
	m_columns = 0;
	m_shapeMatrix = nullptr;
}

int** Figura::getShapeMatrix() const
{
	return m_shapeMatrix;
}

ColorFigura Figura::getColor() const
{
	return m_color;
}

int Figura::getXBoardPivotPosition() const
{
	return m_xBoardPivotPosition;
}

void Figura::setXBoardPivotPosition(int xPosition)
{
	m_xBoardPivotPosition = xPosition;
}

int Figura::getYBoardPivotPosition() const
{
	return m_yBoardPivotPosition;
}

void Figura::setYBoardPivotPosition(int yPosition)
{
	m_yBoardPivotPosition = yPosition;
}

int Figura::getYPivotPosition() const
{
	return m_xPivotPosition;
}

int Figura::getXPivotPosition() const
{
	return m_yPivotPosition;
}

int Figura::getColumns() const
{
	return m_columns;
}

int Figura::getRows() const
{
	return m_rows;
}

void Figura::showShape()
{
	if (m_shapeMatrix == nullptr)
		return;

	cout << "\n-----------\n";
	cout << "Showing Shape Data:\n";
	cout << "xPivot: " << m_xPivotPosition << "\n";
	cout << "yPivot: " << m_yPivotPosition << "\n";
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			cout << m_shapeMatrix[i][j] << " ";
		}

		cout << "\n";
	}
}
