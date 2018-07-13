#include "Out score.h"

SPRITE Outscore::numbersprite_ = nullptr;

Outscore::Outscore(Vector3 pos, int firstscore) :
BIGSCALE_(2.0f),
NORMALSCALE_(1.0f),
SCALEDOWNTIME_(200),
POS_(pos),
CELLSIZE_(Vector2(23.0f, 31.0f))
{

	if (this->numbersprite_ == nullptr){
		numbersprite_ = GraphicsDevice.CreateSpriteFromFile(_T("SCORE\\tabj_number.png"));
	}

	this->score_ = firstscore;
	this->state_ = Outscore::STOP;
	this->time_ = 0;

}

Outscore::~Outscore()
{
	//if (this->numbersprite_ != nullptr){
	//	GraphicsDevice.ReleaseSprite(this->numbersprite_);
	//	this->numbersprite_ = nullptr;
	//}
}

void Outscore::Update(int elapsedtime){

	if (this->state_ == Outscore::SCALEDOWN){

		this->time_ += elapsedtime;

		if (this->time_ > this->SCALEDOWNTIME_){

			this->time_ = 0;
			this->state_ = Outscore::STOP;
		}

	}

}

void Outscore::Draw()
{

	SPRITE sp = this->numbersprite_;
	Vector2 cellsize = this->CELLSIZE_;
	Vector3 pos = this->POS_;
	int score = this->score_;

	float scale;

	if (this->state_ == Outscore::SCALEDOWN){

		float dirscale = this->NORMALSCALE_ - this->BIGSCALE_;
		float timerate = (float)this->time_ / (float)this->SCALEDOWNTIME_;

		scale = this->BIGSCALE_ + (dirscale * timerate);

	}
	else{

		scale = NORMALSCALE_;
	}

	//‚Ç‚±‚ðØ‚èŽæ‚é‚©
	RectWH userect;

	int i = 100;

	do
	{

		int num = score / i % 10;
		userect = RectWH((int)cellsize.x * num, 0, (int)cellsize.x, (int)cellsize.y);
		SpriteBatch.Draw(*numbersprite_, pos, userect, 1.0f, Vector3_Zero, Vector3(CELLSIZE_.x / 2.0f, CELLSIZE_.y / 2.0f, 0.0f), scale);
		pos += Vector3(cellsize.x, 0.0f, 0.0f);

		if (i >= 10){

			i /= 10;
		}
		else{

			break;

		}

	} while (true);
}

void Outscore::Setscore(int score)
{

	if (this->score_ != score) {
		time_ = 0;
	}

	state_ = Outscore::SCALEDOWN;
	score_ = score;
}