#include "Chip_Manager.h"
#include "field.h"
#include "Visitor.h"
#include "Cardboard_Chip.h"

Chip_Manager::Chip_Manager()
{

	keep_timer = 0;

}


Chip_Manager::~Chip_Manager()
{
	//解放はFlyWehgit
}



bool Chip_Manager::Initialize()
{

	return true;
}

int  Chip_Manager::Update()
{
	//チップのUpdateを呼び出し
	for (auto chip : this->chips) chip->Update();

	return 0;

}
void Chip_Manager::Draw()
{
	//チップの描画
	for (auto chip : chips)
	{
		chip->Draw();
	}
}

void Chip_Manager::Accept(Visitor* visitor){

	visitor->Visit(this);

}