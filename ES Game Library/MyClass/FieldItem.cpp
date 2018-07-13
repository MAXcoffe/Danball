#include "FieldItem.h"
#include "Visitor.h"

FieldItem::FieldItem()
{
}


FieldItem::~FieldItem()
{
}

bool FieldItem::Initialize()
{
	//stone(��)������
	stone = GraphicsDevice.CreateModelFromFile(_T("MAP_ITEM\\stone.X"));
	stone->SetPosition(Vector3_Zero);
	stone->SetScale(0.54);

	// �}�e���A���ݒ�
	Material mtrl;
	mtrl.Diffuse = Color(1.0f, 1.0f, 1.0f);
	mtrl.Ambient = Color(1.0f, 1.0f, 1.0f);
	mtrl.Specular = Color(1.0f, 1.0f, 1.0f);
	mtrl.Emissive = Color(1.0f, 1.0f, 1.0f);
	stone->SetMaterial (mtrl);

	return true;
}

int  FieldItem::Update()
{
	return 0;
}

void FieldItem::Draw()
{
	stone->Draw();
	stone->SetPosition(0.0f,4.0f,0.0f);
}

void FieldItem::Accept(Visitor* visitor){

	visitor->Visit(this);

}