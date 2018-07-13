#include "Damage_Visitor.h"
#include"Enemy_FlyWeight.h"
#include "EnemyManager.h"  
#include "Score.h"
#include <typeinfo>

Damage_Visitor::Damage_Visitor(GameObject* object){

	this->enemy = object;

}

void Damage_Visitor::Visit(Acceptor* acceptor){

	if (typeid(*acceptor) == typeid(GameObject)){
		this->Delete_Enemy(acceptor);
		return;
	}

	if (typeid(*acceptor) == typeid(Score)){
		this->Score_CountDown(acceptor);
		return;
	}

}

void Damage_Visitor::Delete_Enemy(Acceptor* acceptor){

	EnemyManager* manager = (EnemyManager*)acceptor;

	std::vector<GameObject* >& enemys = manager->GetEnemys();

	auto itr = std::find(enemys.begin(), enemys.end(), this->enemy);
	if (itr == enemys.end()) return;

	Enemy_FlyWeight::GetInstance().UsedEnemy((Enemy*)(*itr));

}

void Damage_Visitor::Score_CountDown(Acceptor* acceptor){

	Score* score = (Score*)acceptor;
	score->ChengeScore(-10);

}




