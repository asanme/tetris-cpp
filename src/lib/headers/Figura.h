#pragma once

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

typedef enum
{
	UP,
	RIGHT,
	DOWN,
	LEFT
} ShapeRotation;

class Figura
{
 public:
	Figura() : m_shape(NO_FIGURA), m_color(NO_COLOR), m_rotation(), m_xPosition(0), m_yPosition(0)
	{
	}

	void moveVertically();
	void moveHorizontally(int xDirection);

	ShapeRotation getShapeRotation() const;
	void rotateShape(DireccioGir rotationDirection);

	TipusFigura getShape() const;
	void setShape(TipusFigura shape);

	ColorFigura getColor() const;
	void setColor(ColorFigura color);

	int getXPosition() const;
	void setXPosition(int xPosition);

	int getYPosition() const;
	void setYPosition(int yPosition);

 private:
	TipusFigura m_shape;
	ColorFigura m_color;
	ShapeRotation m_rotation;

	int m_xPosition;
	int m_yPosition;
};
