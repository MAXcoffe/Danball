#pragma once
#include "../ESGLib.h"
#include <vector>

class Visitor;
class Acceptor;

class Subject
{
public:
	Subject(){};
	~Subject(){};

	void entryAcceptor(Acceptor*);
	void Notice(Visitor*);

private:

	std::vector<Acceptor*> acceptance;

};