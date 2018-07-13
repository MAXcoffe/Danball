#pragma once 
#include "../ESGLib.h"
#include "Acceptor.h"
#include "Enemy.h"
#include <vector>
#include <functional>
#include <random>


class GameObject;

class EnemyManager : public Acceptor
{
public:
	EnemyManager();
	~EnemyManager();

	virtual int  Update(const MODEL);
	void Draw();

	virtual void Accept(Visitor* visitor);
	std::vector<GameObject*> &GetEnemys(){ return this->enemys; }

	void EntryVisitorPostMethod(std::function<void(Visitor*)> postMethod);

private:

	void CheckDrop(const MODEL field_model,Enemy* enemy);
	bool CheckForward(const MODEL field_model,Enemy* enemy);

	std::vector<GameObject*> enemys;
	int keep_timer;
	std::function<void(Visitor*)> postMethod_;

	std::mt19937 random_;
	std::uniform_real_distribution<float> x_dist_;
	std::uniform_real_distribution<float> z_dist_;

};

