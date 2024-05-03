#pragma once

#include <iostream>

const int MAX_FILA = 8;
const int MAX_COL = 8;

const int ROTATION_UP = 0;
const int ROTATION_RIGHT = 1;
const int ROTATION_DOWN = 2;
const int ROTATION_LEFT = 3;

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
		m_rotationIndex = 0;
		m_shape = NO_FIGURA;
		m_color = NO_COLOR;

		m_rows = 0;
		m_columns = 0;

		m_xPivotPosition = 0;
		m_yPivotPosition = 0;

		m_xBoardPivotPosition = 0;
		m_yBoardPivotPosition = 0;
	}

	// Copy constructor
	Figura(const Figura& figura)
	{
		m_shape = figura.m_shape;
		m_color = figura.m_color;
		m_rotationIndex = figura.m_rotationIndex;

		m_rows = figura.m_rows;
		m_columns = figura.m_columns;

		m_xPivotPosition = figura.m_xPivotPosition;
		m_yPivotPosition = figura.m_yPivotPosition;

		m_xBoardPivotPosition = figura.m_xBoardPivotPosition;
		m_yBoardPivotPosition = figura.m_yBoardPivotPosition;
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

	int getXPivotPosition() const;
	int getYPivotPosition() const;

	int getXBoardPivotPosition() const;
	void setXBoardPivotPosition(int xPosition);

	int getYBoardPivotPosition() const;
	void setYBoardPivotPosition(int yPosition);

	int getRows() const;
	int getColumns() const;

	// Debug only
	void showShape();

 private:
	void freeShapeMatrix();
	void rotateShapeCounterclockwise();
	void rotateShapeClockwise();

	// Other shape information
	TipusFigura m_shape;
	ColorFigura m_color;
	int m_rotationIndex;

	// Matrix information
	int m_rows;
	int m_columns;
	int** m_shapeMatrix;

	// Represents the pivot in the shape matrix
	int m_xPivotPosition;
	int m_yPivotPosition;

	// Represents the pivot inside the board
	int m_xBoardPivotPosition;
	int m_yBoardPivotPosition;
	void setRotationIndex();
};
