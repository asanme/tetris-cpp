#pragma once

#include <iostream>

const int MAX_FILA = 8;
const int MAX_COL = 8;

typedef enum
{
	NO_FIGURA = 0,
	FIGURA_O,
	FIGURA_I,
	FIGURA_T,
	FIGURA_L,
	FIGURA_J,
	FIGURA_Z,
	FIGURA_S
} TipusFigura;

typedef enum
{
	COLOR_NEGRE = 0,
	COLOR_GROC,
	COLOR_BLAUCEL,
	COLOR_MAGENTA,
	COLOR_TARONJA,
	COLOR_BLAUFOSC,
	COLOR_VERMELL,
	COLOR_VERD,
	NO_COLOR
} ColorFigura;

typedef enum
{
	GIR_HORARI = 0,
	GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
 public:
	~Figura()
	{
		freeShapeMatrix();
	}

	Figura()
	{
		m_shapeMatrix = nullptr;
		m_rows = 0;
		m_columns = 0;
		m_shape = NO_FIGURA;
		m_color = NO_COLOR;
		m_xBoardPosition = 0;
		m_yBoardPosition = 0;
	}

	// Copy constructor
	Figura(const Figura& figura)
	{
		m_shape = figura.m_shape;
		m_color = figura.m_color;
		m_rows = figura.m_rows;
		m_columns = figura.m_columns;
		m_xBoardPosition = figura.m_xBoardPosition;
		m_yBoardPosition = figura.m_yBoardPosition;
		m_shapeMatrix = nullptr;

		if (figura.m_shapeMatrix == nullptr)
			return;

		m_shapeMatrix = new int* [m_rows];
		for (int i = 0; i < m_rows; i++)
			m_shapeMatrix[i] = new int[m_columns];

		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_columns; ++j)
			{
				m_shapeMatrix[i][j] = figura.m_shapeMatrix[i][j];
			}
		}
	}

	void moveVertically();
	void moveHorizontally(int xDirection);

	void setShape(TipusFigura shape);
	void rotateShape(DireccioGir rotationDirection);

	int** getShapeMatrix() const;

	ColorFigura getColor() const;

	int getXBoardPosition() const;
	void setXBoardPosition(int xPosition);

	int getYBoardPosition() const;
	void setYBoardPosition(int yPosition);

	int getRows() const;
	int getColumns() const;

	// Debug only
	void showShape();

 private:
	void freeShapeMatrix();
	void rotateShapeClockwise();
	void rotateShapeCounterclockwise();

	// Other shape information
	TipusFigura m_shape;
	ColorFigura m_color;

	// Matrix information
	int m_rows;
	int m_columns;
	int** m_shapeMatrix;

	// Represents the position of the matrix inside the board
	int m_xBoardPosition;
	int m_yBoardPosition;
};
