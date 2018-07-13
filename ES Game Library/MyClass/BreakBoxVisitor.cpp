#include "BreakBoxVisitor.h"
#include "Box_Manager.h"
#include "Chip_Manager.h"
#include "Cardboard_Box.h"
#include <typeinfo>
#include "CardBoard_Box_FlyWeight.h"
#include "CardBoard_Chip_FlyWeight.h"

BreakBoxVisitor::BreakBoxVisitor(Cardboard_Box* targetBox){
	
	this->box_ = targetBox;
	this->boxPos_ = targetBox->GetPosition();
	this->boxPos_.y = 100.0f;

}

BreakBoxVisitor::~BreakBoxVisitor(){

}

void BreakBoxVisitor::Visit(Acceptor* acceptor){

	//
	if (typeid(*acceptor) == typeid(Box_Manager)){
		this->DeleteBox(acceptor);
		return;
	}
	
	if (typeid(*acceptor) == typeid(Chip_Manager)){
		this->CreateChip(acceptor);
		return;
	}
		

}

void BreakBoxVisitor::DeleteBox(Acceptor* acceptor){

	Box_Manager* manager = (Box_Manager*)acceptor;

	std::vector<GameObject* >& boxes = manager->GetBoxes();

	auto itr = std::find(boxes.begin(), boxes.end(), this->box_);
	if (itr == boxes.end()) return;

	CardBoard_Box_FlyWeight::GetInstance().UsedCardboard_Box((Cardboard_Box*)(*itr));

}


void BreakBoxVisitor::CreateChip(Acceptor* acceptor){

	Chip_Manager* manager = (Chip_Manager*)acceptor;

	std::vector<GameObject* >& chips = manager->GetChips();

	//É_ÉìÇ⁄Å[Ç¬ê∂ê¨
	for (int i = 0; i < 10 ; i++)
	{
		Cardboard_Chip*	chip	=	CardBoard_Chip_FlyWeight::GetInstance().GetCardboard_Chip(this->boxPos_);
		chips.push_back((GameObject*) chip);
	}

}