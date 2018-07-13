#pragma once
#include "Visitor_Factory.h"

class DamagePlayer_Visitor_Factory : public Visitor_Factory
{
public:
	DamagePlayer_Visitor_Factory(){};
	~DamagePlayer_Visitor_Factory(){};

	virtual Visitor* factoryMethod(GameObject* object);

};