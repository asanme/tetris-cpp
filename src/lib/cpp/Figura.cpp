#include "../headers/Figura.h"

void Figura::moveHorizontally(int xDirection)
{

}

void Figura::moveVertically()
{

}

void Figura::rotateShape(DireccioGir rotationDirection)
{

}

ShapeRotation Figura::getShapeRotation() const
{
	return m_rotation;
}

TipusFigura Figura::getShape() const
{
	return m_shape;
}

void Figura::setShape(TipusFigura shape)
{
	m_shape = shape;
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
