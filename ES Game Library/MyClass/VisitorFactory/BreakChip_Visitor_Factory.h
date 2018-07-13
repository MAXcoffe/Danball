#pragma once
#include "Visitor_Factory.h"

class BreakChip_Visitor_Factory : public Visitor_Factory
{
public:
	BreakChip_Visitor_Factory(){};
	~BreakChip_Visitor_Factory(){};
	
	virtual Visitor* factoryMethod(GameObject* object);

};