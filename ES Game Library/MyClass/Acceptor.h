#pragma once
#include "../ESGLib.h"

class Visitor;

class Acceptor
{
public:
	Acceptor(){};
	~Acceptor(){};

	virtual void Accept(Visitor* visitor) = 0;

};