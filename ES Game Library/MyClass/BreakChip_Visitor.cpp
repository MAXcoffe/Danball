#include "BreakChip_Visitor.h"
#include "Player.h"
#include "Chip_Manager.h"
#include "CardBoard_Chip_FlyWeight.h"
#include <typeinfo>

BreakChip_Visitor::BreakChip_Visitor(GameObject* object){

	this->chip_ = object;

}

BreakChip_Visitor::~BreakChip_Visitor(){



}

void BreakChip_Visitor::Visit(Acceptor* acceptor){

	if (typeid(*acceptor) == typeid(Chip_Manager)){
		this->Delete_Chip(acceptor);
		return;
	}

	if (typeid(*acceptor) == typeid(Player)){
		this->Player_PowerUp(acceptor);
		return;
	}

}

void  BreakChip_Visitor::Delete_Chip(Acceptor* acceptor){

	Chip_Manager* manager = (Chip_Manager*)acceptor;

	std::vector<GameObject* >& chips = manager->GetChips();

	auto itr = std::find(chips.begin(), chips.end(), this->chip_);
	if (itr == chips.end()) return;

	CardBoard_Chip_FlyWeight::GetInstance().UsedCardboard_Chip((Cardboard_Chip*)(*itr));

}

void  BreakChip_Visitor::Player_PowerUp(Acceptor* acceptor){

	Player* player = (Player*)acceptor;

	player->Add_speeed();

}