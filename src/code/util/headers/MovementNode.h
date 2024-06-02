#pragma once
#include "../../logic/headers/InfoJoc.h"

class MovementNode
{
 public:
	MovementNode(TipusMoviment movementType) : m_movementType(movementType)
	{
	}

	void setNextNode(MovementNode* node);
	MovementNode* getNextNode() const;

	void setMovementType(const TipusMoviment& movementType);
	TipusMoviment getMovementType() const;

 private:
	TipusMoviment m_movementType;
	MovementNode* m_nextNode;
};
