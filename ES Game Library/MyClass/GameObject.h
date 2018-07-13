#pragma once
#include "../ESGLib.h"

class GameObject{

public:

	GameObject() {
	
		
		this->pos_ = Vector3_Zero;

	};
	~GameObject(){};
	
	virtual bool initialize(Vector3) = 0;
	virtual int Update() = 0;
	virtual void Draw() = 0;

	//virtual OrientedBoundingBox GetOBB(){

	//	model_->SetPosition(pos_);
	//	OrientedBoundingBox obb = model_->GetOBB();
	//	return obb;

	//}

	virtual OrientedBoundingBox GetOBB() = 0;
	Vector3 GetPosition(){ return this->pos_; }

protected:

	Vector3 pos_;

};