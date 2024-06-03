#pragma once

#include "MovementNode.h"

class MovementQueue
{
 public:
	~MovementQueue()
	{
		MovementNode* current = m_head;
		while (current != nullptr)
		{
			MovementNode* next = current->getNextNode();
			delete current;
			current = next;
		}

		m_head = nullptr;
	}

	MovementQueue() : m_head(nullptr), m_tail(nullptr)
	{
	}

	void push(TipusMoviment movementType);
	TipusMoviment pop();
	bool isEmpty() const;

 private:
	MovementNode* m_head;
	MovementNode* m_tail;
};

