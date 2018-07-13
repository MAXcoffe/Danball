#pragma once
#include "../ESGLib.h"
#include "Acceptor.h"

class Field : public Acceptor
{
public:
	Field();
	~Field();
	
	virtual bool Initialize();
	virtual int  Update();
	void Draw();

	virtual void Accept(Visitor* visitor);

	MODEL get_model(){
		return field;
	}
private:
	

	
protected:
	MODEL field;
	MODEL around;
	MODEL sky_dome;
	

};

