#pragma once
#include "../ESGLib.h"
#include "../StdAfx.h"
#include <vector>
#include "Acceptor.h"
#include "NormalModelObject.h"

class Cardboard_Box : public NormalModelObject
{
public:
	Cardboard_Box(MODEL model);
	~Cardboard_Box();

	virtual bool initialize(Vector3);
	virtual int  Update();
	void         Draw();

	void Used();
	bool Get_use_flag(){ return use_flag; }

private:

	//�i�{�[����
	bool use_flag;

	//�e�X�g
	MODEL debug_box_;

};





