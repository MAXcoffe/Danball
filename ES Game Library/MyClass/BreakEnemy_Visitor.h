#pragma once 
#include "Visitor.h"

class GameObject;

class BreakEnemy_Visitor : public Visitor
{
public:
	BreakEnemy_Visitor(GameObject*);
	~BreakEnemy_Visitor();

	virtual void Visit(Acceptor* acceptor);

private:

	void  Delete_Enemy(Acceptor*);
	void  Player_PowerUp(Acceptor*);

	GameObject* enemy;

	void ScoreUp(Acceptor*);

};

