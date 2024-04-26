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

TipusFigura Figura::getShape() const
{
	return m_shape;
}

void Figura::setShape(TipusFigura shape)
{
	m_shape = shape;

	int** tmpMatrix;
	int columns;
	int rows;

	switch (shape)
	{
	case FIGURA_O:
		columns = 2;
		rows = 2;
		tmpMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			tmpMatrix[i] = new int[columns];

		tmpMatrix[0][0] = 1;
		tmpMatrix[0][1] = 1;
		tmpMatrix[1][0] = 1;
		tmpMatrix[1][1] = 1;

		break;

	case FIGURA_I:
		columns = 4;
		rows = 4;

		tmpMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			tmpMatrix[i] = new int[columns];

		tmpMatrix[1][0] = 1;
		tmpMatrix[1][1] = 1;
		tmpMatrix[1][2] = 1;
		tmpMatrix[1][3] = 1;

		break;

	case FIGURA_T:
		columns = 3;
		rows = 3;

		tmpMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			tmpMatrix[i] = new int[columns];

		tmpMatrix[1][0] = 1;
		tmpMatrix[1][1] = 1;
		tmpMatrix[1][2] = 1;
		tmpMatrix[0][1] = 1;

		break;

	case FIGURA_L:
		columns = 3;
		rows = 3;

		tmpMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			tmpMatrix[i] = new int[columns];

		tmpMatrix[1][0] = 1;
		tmpMatrix[1][1] = 1;
		tmpMatrix[1][2] = 1;
		tmpMatrix[0][2] = 1;

		break;

	case FIGURA_J:
		columns = 3;
		rows = 3;

		tmpMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			tmpMatrix[i] = new int[columns];

		tmpMatrix[0][0] = 1;
		tmpMatrix[1][0] = 1;
		tmpMatrix[1][1] = 1;
		tmpMatrix[1][2] = 1;

		break;

	case FIGURA_Z:
		columns = 3;
		rows = 3;

		tmpMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			tmpMatrix[i] = new int[columns];

		tmpMatrix[0][0] = 1;
		tmpMatrix[0][1] = 1;
		tmpMatrix[1][1] = 1;
		tmpMatrix[1][2] = 1;

		break;

	case FIGURA_S:
		columns = 3;
		rows = 3;

		tmpMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			tmpMatrix[i] = new int[columns];

		tmpMatrix[0][1] = 1;
		tmpMatrix[0][2] = 1;
		tmpMatrix[1][0] = 1;
		tmpMatrix[1][1] = 1;

		break;
	}

	m_shapeMatrix = tmpMatrix;
	m_columns = columns;
	m_rows = rows;
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
void Figura::showShape()
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
