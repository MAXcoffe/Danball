#include "Box_Manager.h"
#include "field.h"
#include "Visitor.h"
#include "Cardboard_Box.h"
#include "CardBoard_Box_FlyWeight.h"

Box_Manager::Box_Manager()
{
	
	

}


Box_Manager::~Box_Manager()
{

	//データの解放はFlyWeightがやってくれるのでなし

}

bool Box_Manager::Initialize()
{
	//ランダム関数の初期化
	std::random_device seed;
	this->random_ = std::mt19937(seed());

    //ランダムの範囲を指定
	this->x_dist_ = std::uniform_real_distribution<float>(-50.0f, 50.0f);
	this->z_dist_ = std::uniform_real_distribution<float>(-50.0f, 50.0f);

	//ゲーム内時間を初期化
	keep_timer = 0;
	//段ボールをゲームオブジェクトの配列に入れ込む
	this->boxes = std::vector<GameObject*>();

	return true;
}

int  Box_Manager::Update()
{
	//ゲーム内時間が5秒経過毎にランダムな位置に段ボール箱を生成
	this->keep_timer += GameTimer.GetElapsedMilliSecond();
	if (keep_timer >= 5000)
	{
		float x = this->x_dist_(this->random_);
		float z = this->z_dist_(this->random_);

		//ここでFlyWeight(Box)からデータをもらってくる
		Cardboard_Box* box = CardBoard_Box_FlyWeight::GetInstance().GetCardboard_Box(Vector3(x,0.0f,z));
		//生成した段ボールの配列の最後に入れ込む
		this->boxes.push_back(box);
		//ゲーム内時間を-5秒
		this->keep_timer -= 5000;
 	}


	return 0;
}
void Box_Manager::Draw()
{
	//段ボールを描画
	for (auto box : boxes)
	{
		box->Draw();
	}
}

//Visitorの受け入れ
void Box_Manager::Accept(Visitor* visitor){

	visitor->Visit(this);

}