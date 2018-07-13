#pragma once
#include "../ESGLib.h"
#include "Acceptor.h"

class FieldItem : public Acceptor
{
public:
	FieldItem();
	~FieldItem();

	virtual bool Initialize();
	virtual int  Update();
	void Draw();

	virtual void Accept(Visitor* visitor);

private:

	MODEL stone;

};