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

	//�g���ĂȂ��̂����邩�T��
	for (auto chip : chips)
	{
		//���g�p�ł����
		if (!chip->Get_use_flag())
		{
			//��������
			chip->initialize(pos);
			//�ė��p
			return chip;
		}

	}



	//�����܂ŗ����ꍇ�͂��ׂĎg�p�ς݂Ȃ̂�	
	//�������A	
	Cardboard_Chip* cardboard_chip = new Cardboard_Chip(this->model);
	//�z��ɂԂ�����	
	chips.push_back(cardboard_chip);
	//�������̏�	
	cardboard_chip->initialize(pos);
	//���p	
	return cardboard_chip;

}

void CardBoard_Chip_FlyWeight::UsedCardboard_Chip(Cardboard_Chip*use_cardboard_chip){

	use_cardboard_chip->Used();

}