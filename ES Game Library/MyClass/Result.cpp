#include "Result.h"


Result::Result()
{
	sp_result = GraphicsDevice.CreateSpriteFromFile(_T("result.png"));
}



Result::~Result()
{
}



void Result::Update()
{

}



void Result::Draw()
{
	SpriteBatch.DrawSimple(*sp_result, Vector3_Zero);
}