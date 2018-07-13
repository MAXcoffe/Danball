#pragma once
#include "../ESGLib.h"
#include <vector>

class Enemy;

class Enemy_FlyWeight
{
public:

	~Enemy_FlyWeight();
	static Enemy_FlyWeight& GetInstance(){

		static Enemy_FlyWeight Instance;
		return Instance;

	}

	Enemy* GetEnemy(Vector3 pos);
	void UsedEnemy(Enemy*);

private:

	Enemy_FlyWeight();
	std::vector<Enemy*> enemys;
	ANIMATIONMODEL model;

};




