#pragma once

#include "../../logic/headers/Figura.h"
class ShapeNode
{
 public:
	ShapeNode(const Figura& shape)
	{
		m_shape = shape;
		m_nextNode = nullptr;
	}

	void setNextNode(ShapeNode* node);
	ShapeNode* getNextNode() const;

	void setShape(const Figura& shape);
	Figura getShape() const;

 private:
	Figura m_shape;
	ShapeNode* m_nextNode;
};