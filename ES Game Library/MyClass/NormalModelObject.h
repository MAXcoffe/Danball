#pragma once 
#include "GameObject.h"

class NormalModelObject : public GameObject{
public:

	NormalModelObject(MODEL model_) {
	
		this->model_ = model_;
	};
	~NormalModelObject(){};

	virtual bool initialize(Vector3) = 0;
	virtual int Update() = 0;
	virtual void Draw() = 0;

	virtual OrientedBoundingBox GetOBB(){
		model_->SetPosition(pos_);
		OrientedBoundingBox obb = model_->GetOBB();
		return obb;
	};

protected:

	Vector3 pos_;
	MODEL  model_;
};