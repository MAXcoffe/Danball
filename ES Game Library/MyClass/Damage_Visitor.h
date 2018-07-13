#pragma once
#include "../ESGLib.h"
#include "Visitor.h"

class GameObject;
class Acceptor;


class Damage_Visitor :  public Visitor
{
public:
	Damage_Visitor(GameObject* object);
	~Damage_Visitor(){};

	virtual void Visit(Acceptor* acceptor);

private:

	void Delete_Enemy(Acceptor* acceptor);
	void Score_CountDown(Acceptor* acceptor);

	GameObject* enemy;

};