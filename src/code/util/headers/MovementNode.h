#pragma once
#include "../../logic/headers/InfoJoc.h"

// TODO Finish class
class MovementNode
{
 public:
	void setNextNode(MovementNode* node);
	MovementNode* getNextNode(MovementNode* node) const;

	void setMovementType(const TipusMoviment& movementType);
	TipusMoviment getMovementType() const;

 private:
	TipusMoviment m_movementType;
	MovementNode* m_nextNode;
};
