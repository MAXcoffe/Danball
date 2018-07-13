/**
* @file   Enemy.cpp
* @brief  敵クラスcppファイル
* @author reo okuhama
* @date   2018/6/30
*/

#include "Enemy.h"
#include "Visitor.h"
#include <random>
#include "AnimationObject.h"

/**
 * @fn コンストラクタ
 * @param use_flag 使用状況
 * @param state    状態
 */
Enemy::Enemy(ANIMATIONMODEL model) : AnimationObject(model)
{
	use_flag = false;
	state = MOVE_DROP;

}

/**
 * @fn デストラクタ
 */
Enemy::~Enemy()
{
}

/**
 * @fn 初期化
 * @param (pos) 　 初期座標
 * @param state    状態
 * @param use_flag 使用状況
 * @return true...成功 / false...失敗
 */
bool Enemy::initialize(Vector3 pos){

	this->pos_ = pos;
	state = MOVE_DROP;
	use_flag = true;

	return true;
}

/**
* @fn 動作
* @return 0...正常終了 / 0以外...異常終了
*/
int Enemy::Update(){

	switch (this->state){
	//落ちる
	case (MOVE_DROP):{

		pos_.y -= 2.0f;

		} break;
	
	//手前
		case(MOVE_FORWARD) : {

			pos_.z -= 0.5f;

		}break;
	}

	return 0;

}

/**
　* @fn ゲッター
　* @preturn state 状態 
　*/
Enemy::MOVESTATE Enemy::Get_state(){
	return state;
} 

/**
　* @fn セッター
  * @preturn state 状態
  * @pmove_state   動いてる状態 
  */
void Enemy::Set_state(MOVESTATE move_state){

	this->state = move_state;

}

/**
* @fn 描画
* @param AdvanceTime アニメーション速度
* @param SetPosition 座標設定
*/
void  Enemy::Draw(){

	animation_model->SetPosition(pos_);
	animation_model->AdvanceTime(0.016);
	animation_model->Draw();

}

/**
 * @fn 　　　　　 使用状態
 * @puse_flag 　　使用状況
 * @pmove_state   動いてる状態
 */
void Enemy::Used(){ use_flag = false; }