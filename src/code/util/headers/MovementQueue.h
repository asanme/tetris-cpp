#pragma once

#include "MovementNode.h"

// TODO Finish class
class MovementQueue
{
 public:
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

