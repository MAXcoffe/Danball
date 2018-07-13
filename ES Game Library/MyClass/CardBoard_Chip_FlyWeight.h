#pragma once
#include "../ESGLib.h"
#include <vector>

class Cardboard_Chip;


class CardBoard_Chip_FlyWeight
{
public:

	~CardBoard_Chip_FlyWeight();
	static CardBoard_Chip_FlyWeight& GetInstance(){

		static CardBoard_Chip_FlyWeight Instance;
		return Instance;

	}

	Cardboard_Chip* GetCardboard_Chip(Vector3 pos);
	void UsedCardboard_Chip(Cardboard_Chip*);

private:

	CardBoard_Chip_FlyWeight();
	std::vector<Cardboard_Chip*> chips;
	MODEL model;

};

