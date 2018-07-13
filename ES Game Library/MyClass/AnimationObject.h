#pragma once
#include "GameObject.h"

class AnimationObject : public GameObject{
public:

	AnimationObject(ANIMATIONMODEL animationmodel) {

		this->animation_model = animationmodel;

	};
	~AnimationObject(){};

	virtual bool initialize(Vector3) = 0;
	virtual int Update() = 0;
	virtual void Draw() = 0;

	virtual OrientedBoundingBox GetOBB(){
		animation_model->SetPosition(pos_);
		OrientedBoundingBox obb = animation_model->GetOBB();
		return obb;
	};

protected:

	Vector3 pos_;
	ANIMATIONMODEL animation_model;
};

