#pragma once
#include "../ESGLib.h"
#include "Acceptor.h"
#include <vector>
#include <random>

class GameObject;

class Chip_Manager : public Acceptor
{
public:
	Chip_Manager();
	~Chip_Manager();

	virtual bool Initialize();
	virtual int  Update();
	void Draw();

	std::vector<GameObject*>& GetChips(){ return this->chips; }
	virtual void Accept(Visitor* visitor);

private:

	std::vector<GameObject*> chips;

	int keep_timer;

	std::mt19937 random_;
	std::uniform_real_distribution<float> x_dist_;


};

