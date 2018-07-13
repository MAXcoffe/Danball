#include "Score.h"
#include "Visitor.h"

bool Score::Initialize(){

	this->out_score = new Outscore(Vector3_Zero, 100);
	this->score = 0;
	return 0;
}

int Score::Update(){

	int elapsedtime = GameTimer.GetElapsedMilliSecond();
	out_score->Update(elapsedtime);
	return true;
}

void Score::Draw(){

	SpriteBatch.Begin();
	out_score->Draw();
	SpriteBatch.End();

}

void Score::Accept(Visitor* visitor){

	visitor->Visit(this);


}

