#include "headers/ShapeQueue.h"

void ShapeQueue::push(const Figura& shape)
{
	if (m_head == nullptr)
	{
		m_head = new ShapeNode(shape);
	}
	else if (m_tail == nullptr)
	{
		m_tail = new ShapeNode(shape);
		m_head->setNextNode(m_tail);
	}
	else
	{
		ShapeNode* newTailNode = new ShapeNode(shape);
		m_tail->setNextNode(newTailNode);
		m_tail = newTailNode;
	}
}

Figura* ShapeQueue::pop()
{
	if (m_head == nullptr)
	{
		throw std::runtime_error("Attempted to pop from an empty queue");
	}

	Figura shapeCopy = m_head->getShape();
	ShapeNode* oldHead = m_head;
	m_head = m_head->getNextNode();

	if (m_head == m_tail)
	{
		m_tail = nullptr;
	}

	delete oldHead;

	return new Figura(shapeCopy);
}
bool ShapeQueue::isEmpty()
{
	return m_head == nullptr;
}
