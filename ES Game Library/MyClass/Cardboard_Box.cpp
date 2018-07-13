#include "Cardboard_Box.h"
#include "Visitor.h"
#include  "NormalModelObject.h"

Cardboard_Box::Cardboard_Box(MODEL model) : NormalModelObject(model){
	
	use_flag = false;

	OrientedBoundingBox obb = model->GetOBB();

	SimpleShape   box_shape;
	box_shape.Type = Shape_Box;
	box_shape.Width = obb.Radius.x * 2.0f;
	box_shape.Height = obb.Radius.y * 2.0f;
	box_shape.Depth = obb.Radius.z * 2.0f;
	debug_box_ = GraphicsDevice.CreateModelFromSimpleShape(box_shape);

}

Cardboard_Box::~Cardboard_Box(){

	

}



bool Cardboard_Box::initialize(Vector3 position){

	//段ボール箱　初期化
	this->pos_ = position;

	use_flag = true;


	return true;
}

int  Cardboard_Box::Update(){
    

	
	return 0;
}

void  Cardboard_Box::Draw(){

	model_->SetPosition(pos_);
	model_->Draw();


}

void Cardboard_Box::Used(){

	use_flag = false;

}