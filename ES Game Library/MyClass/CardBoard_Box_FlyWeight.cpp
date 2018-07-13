/**
* @file   CardBoard_Box_FlyWeight.h
* @brief  段ボールのFlyWeightクラス
* @author reo okuhama
* @date   2018/7/2
*/

#include "CardBoard_Box_FlyWeight.h"
#include "Cardboard_Box.h"

/**
* @fn コンストラクタ
* @param model 3Dモデル
*/
CardBoard_Box_FlyWeight::CardBoard_Box_FlyWeight(){

	model = GraphicsDevice.CreateModelFromFile(_T("GAME_ITEM\\dan_box.X"));
	model->SetScale(0.25f);

}

/**
* @fn デストラクタ
*/
CardBoard_Box_FlyWeight::~CardBoard_Box_FlyWeight(){



}

/**
 * @fn 動作
 * @param pos          Cardboard_Boxからもらってきた座標
 * @param Get_use_flag use_flagを取得するための関数
 * @return true...成功 / false...失敗
 */
Cardboard_Box* CardBoard_Box_FlyWeight::GetCardboard_Box(Vector3 pos){

	//使ってないのがあるか探す
	for (auto box : boxes)
	{
		//未使用であれば
		if (!box->Get_use_flag())
		{
			//初期化し
			box->initialize(pos);
			//再利用
			return box;
		}

	}

	//ここまで来た場合はすべて使用済みなので
	//生成し、
	Cardboard_Box* cardboard_box = new Cardboard_Box(this->model);
	//配列にぶちこみ
	boxes.push_back(cardboard_box);
	//初期化の上
	cardboard_box->initialize(pos);
	//利用
	return cardboard_box;

}

/**
 * @fn  boxが使われているか
*/
void CardBoard_Box_FlyWeight::UsedCardboard_Box(Cardboard_Box* use_cardboard_box){

	use_cardboard_box->Used();

}