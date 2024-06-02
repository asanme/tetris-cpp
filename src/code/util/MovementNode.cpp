#include "headers/MovementNode.h"

void MovementNode::setNextNode(MovementNode* node)
{
	m_nextNode = node;
}

MovementNode* MovementNode::getNextNode(MovementNode* node) const
{
	return m_nextNode;
}

void MovementNode::setMovementType(const TipusMoviment& movementType)
{
	m_movementType = movementType;
}

TipusMoviment MovementNode::getMovementType() const
{
	return m_movementType;
}
