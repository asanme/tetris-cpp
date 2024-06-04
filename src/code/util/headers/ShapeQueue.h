#pragma once

#include "ShapeNode.h"
class ShapeQueue
{
 public:
	ShapeQueue() : m_head(nullptr), m_tail(nullptr)
	{
	}

	void push(const Figura& shape);
	Figura* pop();
	bool isEmpty() const;
	const ShapeNode* getHead()
	{
		return m_head;
	}

 private:
	ShapeNode* m_head;
	ShapeNode* m_tail;
};
