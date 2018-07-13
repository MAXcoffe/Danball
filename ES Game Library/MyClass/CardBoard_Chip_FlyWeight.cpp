#include "CardBoard_Chip_FlyWeight.h"
#include "Cardboard_Chip.h"

CardBoard_Chip_FlyWeight::CardBoard_Chip_FlyWeight(){

	model = GraphicsDevice.CreateModelFromFile(_T("GAME_ITEM\\dan_item.X"));
	model->SetScale(0.5f);

}

CardBoard_Chip_FlyWeight::~CardBoard_Chip_FlyWeight(){

	for (auto chip : this->chips){

		delete chip;

	}

}


Cardboard_Chip* CardBoard_Chip_FlyWeight::GetCardboard_Chip(Vector3 pos){

	//使ってないのがあるか探す
	for (auto chip : chips)
	{
		//未使用であれば
		if (!chip->Get_use_flag())
		{
			//初期化し
			chip->initialize(pos);
			//再利用
			return chip;
		}

	}



	//ここまで来た場合はすべて使用済みなので	
	//生成し、	
	Cardboard_Chip* cardboard_chip = new Cardboard_Chip(this->model);
	//配列にぶちこみ	
	chips.push_back(cardboard_chip);
	//初期化の上	
	cardboard_chip->initialize(pos);
	//利用	
	return cardboard_chip;

}

void CardBoard_Chip_FlyWeight::UsedCardboard_Chip(Cardboard_Chip*use_cardboard_chip){

	use_cardboard_chip->Used();

}