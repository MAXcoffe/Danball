#pragma once 
#include "../ESGLib.h"
class Acceptor;

class Visitor
{
public:
	Visitor(){};
	~Visitor(){};

	virtual void Visit(Acceptor* acceptor) = 0;

private:

};