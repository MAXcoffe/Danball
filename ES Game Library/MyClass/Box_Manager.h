#pragma once
#include "../ESGLib.h"
#include "Acceptor.h"
#include <vector>
#include <random>

class GameObject;

class Box_Manager : public Acceptor
{
public:
	Box_Manager();
	~Box_Manager();

	virtual bool Initialize();
	virtual int  Update();
	void Draw();

	std::vector<GameObject*>& GetBoxes(){ return this->boxes; }

	virtual void Accept(Visitor* visitor);
	
private:

	std::vector<GameObject*> boxes;
	
	int keep_timer;

	std::mt19937 random_;
	std::uniform_real_distribution<float> x_dist_;
	std::uniform_real_distribution<float> z_dist_;


	
};

