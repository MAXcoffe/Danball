#pragma once

#include "../../ESGLib.h"
#include "Visitor_Factory.h"

class BreakBox_Visitor_Factory : Visitor_Factory
{
public:
	BreakBox_Visitor_Factory(){};
	~BreakBox_Visitor_Factory(){};

	virtual Visitor* factoryMethod(GameObject* object);

};

