#include "Field.h"
#include "Visitor.h"



Field::Field()
{
}


Field::~Field()
{
}

bool Field::Initialize()
{
	
	

	field = GraphicsDevice.CreateModelFromFile(_T("BG\\BG.X"));
	field->SetPosition(Vector3(-10.0f, 0.0f, -5.0f));
	field->SetScale(1.25, 1.0f, 1.0f);

	around = GraphicsDevice.CreateModelFromFile(_T("BG\\wood04.X"));
	around->SetPosition(Vector3(10.0f,0.0f,20.0f));
	around->SetRotation(0,0,0);
	around->SetScale(0.40);


	sky_dome = GraphicsDevice.CreateModelFromFile(_T("SKYDOME\\SkyDome.x"));
	sky_dome->SetPosition(Vector3_Zero);
	sky_dome->SetScale(2.0f);

	return true;

}


int Field::Update()
{
	return 0;
}


void Field::Draw()
{
	field->Draw();
	around->Draw();
	sky_dome->Draw();

}


void Field::Accept(Visitor* visitor){

	visitor->Visit(this);

}