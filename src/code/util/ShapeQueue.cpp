#include "headers/ShapeQueue.h"

void ShapeQueue::push(const Figura& shape)
{
	ShapeNode* newNode = new ShapeNode(shape);
	if (m_head == nullptr)
		m_head = newNode;
	else
		m_tail->setNextNode(newNode);

	m_tail = newNode;
}

Figura* ShapeQueue::pop()
{
	if (m_head == nullptr)
		return nullptr;

	Figura* shapeCopy = new Figura(m_head->getShape());
	ShapeNode* oldHead = m_head;
	m_head = m_head->getNextNode();

	// If there's no more elements
	if (m_head == nullptr)
		m_tail = nullptr;

	delete oldHead;
	return shapeCopy;
}

bool ShapeQueue::isEmpty() const
{
	return m_head == nullptr;
}
