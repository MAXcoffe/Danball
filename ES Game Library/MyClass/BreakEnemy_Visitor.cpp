#include "BreakEnemy_Visitor.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Enemy_FlyWeight.h"
#include <typeinfo>
#include "Score.h"

BreakEnemy_Visitor::BreakEnemy_Visitor(GameObject* object){

	this->enemy = object;

}

BreakEnemy_Visitor::~BreakEnemy_Visitor(){



}

void BreakEnemy_Visitor::Visit(Acceptor* acceptor){

	if (typeid(*acceptor) == typeid(EnemyManager)){
		this->Delete_Enemy(acceptor);
		return;
	}

	if (typeid(*acceptor) == typeid(Player)){
		this->Player_PowerUp(acceptor);
		return;
	}

	if (typeid(*acceptor) == typeid(Score)){
		this->ScoreUp(acceptor);
		return;
	}


}

void  BreakEnemy_Visitor::Delete_Enemy(Acceptor* acceptor){

	EnemyManager* manager = (EnemyManager*)acceptor;

	std::vector<GameObject* >& chips = manager->GetEnemys();

	auto itr = std::find(chips.begin(), chips.end(), this->enemy);
	if (itr == chips.end()) return;

	Enemy_FlyWeight::GetInstance().UsedEnemy((Enemy*)(*itr));

}

void  BreakEnemy_Visitor::Player_PowerUp(Acceptor* acceptor){

	Player* player = (Player*)acceptor;

	player->Add_speeed();

}

void BreakEnemy_Visitor::ScoreUp(Acceptor* acceptor){

	Score* score = (Score*)acceptor;

	score->ChengeScore(+10);

}