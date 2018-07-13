#pragma once
#include "../ESGLib.h"
#include <vector>

class Outscore
{
public:

	Outscore(Vector3 pos, int firstscore = 0);
	~Outscore();
	void Update(int elapsedtime);
	void Draw();

	void Setscore(int score);

private:

	enum STATE
	{

		SCALEDOWN,
		STOP

	}state_;


	const float BIGSCALE_;
	const float NORMALSCALE_;
	const int SCALEDOWNTIME_;
	const Vector2 CELLSIZE_;
	const Vector3 POS_;

	static SPRITE numbersprite_;

	int time_;
	int score_;

};

