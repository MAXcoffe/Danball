#include "EnemyManager.h"
#include "Visitor.h"
#include "Enemy.h"
#include "Enemy_FlyWeight.h"
#include "Damage_Visitor.h"

EnemyManager::EnemyManager(){

	this->keep_timer = 0;
	this->postMethod_ = nullptr;
	std::random_device seed;

	this->random_ = std::mt19937(seed());
	this->x_dist_ = std::uniform_real_distribution<float>(-100.0f, 100.0f);

}

EnemyManager::~EnemyManager(){

}



int  EnemyManager::Update(const MODEL field_model){

	this->keep_timer += GameTimer.GetElapsedMilliSecond();
	if (keep_timer >= 5000)
	{
        //ここでランダム生成
		float x = this->x_dist_(this->random_);
		float z = this->x_dist_(this->random_);


		//ここでFlyWeightからデータをもらってくる
		Enemy* box = Enemy_FlyWeight::GetInstance().GetEnemy(Vector3(x, 0.0f, 100.0f));

		this->enemys.push_back(box);

		this->keep_timer -= 5000;
	}

	auto itr = this->enemys.begin();

	while (itr != this->enemys.end()){
		(*itr)->Update();
		switch(((Enemy*)(*itr))->Get_state()){
		case Enemy::MOVE_DROP:
			this->CheckDrop(field_model,(Enemy*)(*itr));
			break;

		case Enemy::MOVE_FORWARD:
			if (!this->CheckForward(field_model, (Enemy*)(*itr))){

				//着地してないエネミーを消す
				if (this->postMethod_ != nullptr){
					
					Damage_Visitor damage_visitor((*itr));
					postMethod_(&damage_visitor);
					itr = this->enemys.erase(itr);

					continue;
				}

			}
		}
		itr++;
	}

	return 0;

}

void EnemyManager::CheckDrop(const MODEL field_model, Enemy* enemy){

	//地面に着地->ステート変更
	Vector3 enemyPos = enemy->GetPosition();
	float length = 0.0f;
	field_model->IntersectRay(enemyPos, Vector3_Down, &length);

	if (length <= 1.0f)
	{
		enemy->Set_state(Enemy::MOVE_FORWARD);
	}

}

bool EnemyManager::CheckForward(const MODEL field_model,Enemy* enemy){

	Vector3 enemyPos = enemy->GetPosition();

	return field_model->IntersectRay(enemyPos, Vector3_Down);
}

void  EnemyManager::Draw(){

	for (auto enemy : enemys)
	{
		enemy->Draw();
	}
}

void EnemyManager::Accept(Visitor* visitor){
	visitor->Visit(this);
}

void EnemyManager::EntryVisitorPostMethod(std::function<void(Visitor*)> postMethod){

	this->postMethod_ = postMethod;

}