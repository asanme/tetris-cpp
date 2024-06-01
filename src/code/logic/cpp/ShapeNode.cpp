#include "../headers/ShapeNode.h"

void ShapeNode::setNextNode(ShapeNode* node)
{
	m_nextNode = node;
}

ShapeNode* ShapeNode::getNextNode() const
{
	return m_nextNode;
}

void ShapeNode::setShape(const Figura& shape)
{
	m_shape = shape;
}

Figura ShapeNode::getShape() const
{
	return m_shape;
}
