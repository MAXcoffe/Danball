#pragma once 
#include "../ESGLib.h"

class Acceptor;

class ItemDeleteVisitor
{
public:
	ItemDeleteVisitor(){};
	~ItemDeleteVisitor(){};

	virtual void Visit(Acceptor* acceptor) = 0;

private:

};