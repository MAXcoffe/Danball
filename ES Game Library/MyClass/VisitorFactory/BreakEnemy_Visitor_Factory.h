#pragma once
#include "Visitor_Factory.h"

class BreakEnemy_Visitor_Factory : public Visitor_Factory
{
public:
	BreakEnemy_Visitor_Factory(){};
	~BreakEnemy_Visitor_Factory(){};

	virtual Visitor* factoryMethod(GameObject* object);

};