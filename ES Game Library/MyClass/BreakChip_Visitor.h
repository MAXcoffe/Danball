#pragma once 
#include "Visitor.h"

class GameObject;

class BreakChip_Visitor : public Visitor
{
public:
	BreakChip_Visitor(GameObject*);
	~BreakChip_Visitor();

	virtual void Visit(Acceptor* acceptor);

private:

	void  Delete_Chip(Acceptor*);
	void  Player_PowerUp(Acceptor*);

	GameObject* chip_;

};

