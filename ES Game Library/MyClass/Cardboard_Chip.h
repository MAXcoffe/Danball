#pragma once
#include "../ESGLib.h"
#include "../StdAfx.h"
#include <vector>
#include "Acceptor.h"
#include "NormalModelObject.h"

class Cardboard_Chip : public NormalModelObject
{
public:
	Cardboard_Chip(MODEL model);
	~Cardboard_Chip();

	virtual bool initialize(Vector3);
	virtual int  Update();
	void         Draw();

	void Used();
	bool Get_use_flag(){ return use_flag; }


private:

	//段ボールチップ
	Vector3 chip_bezier[4];

	float   bezier_t;
	bool    use_flag;

};