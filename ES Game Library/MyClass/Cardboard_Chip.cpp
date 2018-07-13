#include "Cardboard_Chip.h"
#include "Visitor.h"
#include <random>
#include "NormalModelObject.h"

Cardboard_Chip::Cardboard_Chip(MODEL model) : NormalModelObject(model){

	this->use_flag = false;

}

Cardboard_Chip::~Cardboard_Chip(){



}

bool Cardboard_Chip::initialize(Vector3 position){

	//段ボール箱　初期化
	this->pos_ = position;
	
	std::random_device seed;
	std::mt19937 random = std::mt19937(seed());
	std::uniform_real_distribution<float> dist = std::uniform_real_distribution<float>(0.0f, 360.0f);
	std::uniform_real_distribution<float> fly_dist = std::uniform_real_distribution<float>(20.0f, 60.0f);

	float angle = dist(random);
	float flyLength = fly_dist(random);

	float y = MathHelper_Sin(angle);
	float x = MathHelper_Cos(angle);

	this->chip_bezier[0] = position;
	this->chip_bezier[1] = position + Vector3(x * (flyLength / 3.0f), 30.0f, (flyLength / 3.0f));
	this->chip_bezier[2] = position + Vector3(x * (flyLength / 3.0f * 2.0f), 30.0f, y * (flyLength / 3.0f * 2.0f));
	this->chip_bezier[3] = position + Vector3(x * flyLength, 0.0f, y * flyLength);
	this->chip_bezier[3].y = 5.0f;

	bezier_t = 0;

	use_flag = true;

	return true;

}

int  Cardboard_Chip::Update(){
	
	if (bezier_t < 1)
	{
		bezier_t += 0.01f;
		this->pos_ = Vector3_Bezier(chip_bezier[0], chip_bezier[1], chip_bezier[2], chip_bezier[3], bezier_t);
	}

	return 0;

}

void Cardboard_Chip::Draw(){

	model_->SetPosition(pos_);
	model_->Draw();
}

void Cardboard_Chip::Used(){

	use_flag = false;

}