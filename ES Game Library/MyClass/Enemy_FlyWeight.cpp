#include "Enemy_FlyWeight.h"
#include "Enemy.h"

Enemy_FlyWeight::Enemy_FlyWeight(){

	//SimpleShape   box_shape;
	//box_shape.Type = Shape_Box;
	//box_shape.Width = 5.0f;
	//box_shape.Height = 5.0f;
	//box_shape.Depth = 5.0f;
	//model = GraphicsDevice.CreateModelFromSimpleShape(box_shape);

	model = GraphicsDevice.CreateAnimationModelFromFile(_T("ENEMY\\hukumen1.X"));
	model->SetRotation(0.0, 90.0, 0.0);
}

Enemy_FlyWeight::~Enemy_FlyWeight(){
	for (auto enemy : this->enemys){

		delete enemy;

	}
}

Enemy* Enemy_FlyWeight::GetEnemy(Vector3 pos){

	//使ってないのがあるか探す
	for (auto enemy : enemys)
	{
		//未使用であれば
		if (!enemy->Get_use_flag())
		{
			//初期化し
			enemy->initialize(pos);
			//再利用
			return enemy;
		}

	}



	//ここまで来た場合はすべて使用済みなので
	//生成し、
	Enemy* enemy = new Enemy(this->model);
	//配列にぶちこみ
	enemys.push_back(enemy);
	//初期化の上
	enemy->initialize(pos);
	//利用
	return enemy;

}



void Enemy_FlyWeight::UsedEnemy(Enemy* use_enemy){
	use_enemy->Used(); 
}