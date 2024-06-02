#import "headers/MovementQueue.h"
#include "headers/ShapeQueue.h"

void MovementQueue::push(TipusMoviment movementType)
{
	MovementNode* newNode = new MovementNode(movementType);
	if (m_head == nullptr)
		m_head = newNode;
	else
		m_tail->setNextNode(newNode);

	m_tail = newNode;
}

TipusMoviment MovementQueue::pop()
{
	TipusMoviment movementType = m_head->getMovementType();
	MovementNode* oldHead = m_head;
	m_head = m_head->getNextNode();

	// If there's no more elements
	if (m_head == nullptr)
		m_tail = nullptr;

	delete oldHead;
	return movementType;
}

bool MovementQueue::isEmpty() const
{
	return m_head == nullptr;
}
