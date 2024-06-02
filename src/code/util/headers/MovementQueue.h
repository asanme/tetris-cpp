#pragma once

#include "MovementNode.h"

class MovementQueue
{
 public:
	MovementQueue() : m_head(nullptr), m_tail(nullptr)
	{
	}

	void push();
	MovementNode* pop();

 private:
	MovementNode* m_head;
	MovementNode* m_tail;
};
