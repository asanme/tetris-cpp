#include "../headers/Figura.h"
#include <iostream>

using namespace std;

void Figura::moveHorizontally(int xDirection)
{

}

void Figura::moveVertically()
{

}

void Figura::rotateShape(DireccioGir rotationDirection)
{

}

void Figura::setShape(TipusFigura shape)
{
	if (m_shapeMatrix != nullptr)
	{
		freeShapeMatrix();
	}

	m_shape = shape;

	int** tmpMatrix = nullptr;
	int columns;
	int rows;

	switch (shape)
	{
	case FIGURA_O:
		rows = 2;
		columns = 2;

		tmpMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			tmpMatrix[i] = new int[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				tmpMatrix[i][j] = 0;

		tmpMatrix[0][0] = 1;
		tmpMatrix[0][1] = 1;
		tmpMatrix[1][0] = 1;
		tmpMatrix[1][1] = 1;

		break;

	case FIGURA_I:
		rows = 4;
		columns = 4;

		tmpMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			tmpMatrix[i] = new int[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				tmpMatrix[i][j] = 0;

		tmpMatrix[1][0] = 1;
		tmpMatrix[1][1] = 1;
		tmpMatrix[1][2] = 1;
		tmpMatrix[1][3] = 1;

		break;

	case FIGURA_T:
		rows = 3;
		columns = 3;

		tmpMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			tmpMatrix[i] = new int[columns];
		}

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				tmpMatrix[i][j] = 0;

		tmpMatrix[1][0] = 1;
		tmpMatrix[1][1] = 1;
		tmpMatrix[1][2] = 1;
		tmpMatrix[0][1] = 1;

		break;

	case FIGURA_L:
		rows = 3;
		columns = 3;

		tmpMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			tmpMatrix[i] = new int[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				tmpMatrix[i][j] = 0;

		tmpMatrix[1][0] = 1;
		tmpMatrix[1][1] = 1;
		tmpMatrix[1][2] = 1;
		tmpMatrix[0][2] = 1;

		break;

	case FIGURA_J:
		rows = 3;
		columns = 3;

		tmpMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			tmpMatrix[i] = new int[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				tmpMatrix[i][j] = 0;

		tmpMatrix[0][0] = 1;
		tmpMatrix[1][0] = 1;
		tmpMatrix[1][1] = 1;
		tmpMatrix[1][2] = 1;

		break;

	case FIGURA_Z:
		rows = 3;
		columns = 3;

		tmpMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			tmpMatrix[i] = new int[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				tmpMatrix[i][j] = 0;

		tmpMatrix[0][0] = 1;
		tmpMatrix[0][1] = 1;
		tmpMatrix[1][1] = 1;
		tmpMatrix[1][2] = 1;

		break;

	case FIGURA_S:
		rows = 3;
		columns = 3;

		tmpMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			tmpMatrix[i] = new int[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				tmpMatrix[i][j] = 0;

		tmpMatrix[0][1] = 1;
		tmpMatrix[0][2] = 1;
		tmpMatrix[1][0] = 1;
		tmpMatrix[1][1] = 1;

		break;
	}

	if (tmpMatrix != nullptr)
	{
		m_shapeMatrix = tmpMatrix;
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
