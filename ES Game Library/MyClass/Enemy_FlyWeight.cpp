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

	//�g���ĂȂ��̂����邩�T��
	for (auto enemy : enemys)
	{
		//���g�p�ł����
		if (!enemy->Get_use_flag())
		{
			//��������
			enemy->initialize(pos);
			//�ė��p
			return enemy;
		}

	}



	//�����܂ŗ����ꍇ�͂��ׂĎg�p�ς݂Ȃ̂�
	//�������A
	Enemy* enemy = new Enemy(this->model);
	//�z��ɂԂ�����
	enemys.push_back(enemy);
	//�������̏�
	enemy->initialize(pos);
	//���p
	return enemy;

}



void Enemy_FlyWeight::UsedEnemy(Enemy* use_enemy){
	use_enemy->Used(); 
}