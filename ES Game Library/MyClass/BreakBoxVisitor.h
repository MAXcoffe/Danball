#pragma once
#include "Visitor.h"

class Acceptor;
class Cardboard_Box;

class BreakBoxVisitor : public Visitor{

public:

	BreakBoxVisitor(Cardboard_Box* targetBox);
	~BreakBoxVisitor();

	virtual void Visit(Acceptor* acceptor);

private:

	void DeleteBox( Acceptor* acceptor);

	void CreateChip(Acceptor* acceptor);

	Cardboard_Box* box_;
	Vector3 boxPos_;

};