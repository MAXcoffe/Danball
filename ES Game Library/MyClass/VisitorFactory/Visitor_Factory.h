#pragma once

#include "../../ESGLib.h"

class GameObject;
class Visitor;

class Visitor_Factory
{
public:
	Visitor_Factory(){};
	~Visitor_Factory(){};

	Visitor* Create(GameObject* object)
	{
		return factoryMethod(object);
	}

private:

protected:
	virtual Visitor* factoryMethod(GameObject* object) = 0;



};