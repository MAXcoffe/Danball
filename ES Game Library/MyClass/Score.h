#pragma once
#include "../ESGLib.h"
#include "Acceptor.h"
#include "Out score.h"

class Score :public Acceptor
{
public:
	Score(){
	
		this->out_score = nullptr;
	
	};
	~Score(){
	
		if (this->out_score != nullptr) delete this->out_score;
	
	};
	
	virtual bool Initialize();
	virtual int  Update();
	void Draw();

	void ChengeScore(int value){ 
	
		this->score += value;
		if (this->score < 0) this->score = 0;
		this->out_score->Setscore(this->score);

	}

	virtual void Accept(Visitor* visitor);


private:

	int score;
	Outscore* out_score;

};