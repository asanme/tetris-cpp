#pragma once

#include "ShapeNode.h"
class ShapeQueue
{
 public:
	~ShapeQueue()
	{
		ShapeNode* current = m_head;
		while (current != nullptr)
		{
			ShapeNode* next = current->getNextNode();
			delete current;
			current = next;
		}

		m_head = nullptr;
	}

	ShapeQueue() : m_head(nullptr), m_tail(nullptr)
	{
	}

	void push(const Figura& shape);
	Figura* pop();
	bool isEmpty() const;

 private:
	ShapeNode* m_head;
	ShapeNode* m_tail;
};
