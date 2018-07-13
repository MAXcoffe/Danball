/**
* @file   OBBcheck.cpp
* @brief  コリジョンチェッククラスcppファイル
* @author reo okuhama
* @date   2018/6/28
*/

#include "OBBcheck.h"
#include <typeinfo>
#include "Player.h"
#include "Cardboard_Box.h"
#include "BreakBoxVisitor.h"
#include "VisitorFactory\BreakBox_Visitor_Factory.h"
#include "VisitorFactory\BreakChip_Visitor_Factory.h"
#include "Cardboard_Chip.h"
#include "Enemy.h"
#include "VisitorFactory\DamagePlayer_Visitor_Factory.h"
#include "VisitorFactory\BreakEnemy_Visitor_Factory.h"

/**
 * @fn コンストラクタ
 */
OBBcheck::OBBcheck(){

}

/**
 * @fn デストラクタ
 */
OBBcheck::~OBBcheck(){



}


/**
 * @fn 動作
 * @return 0...正常終了 / 0以外...異常終了
 */
void OBBcheck::Update(std::vector<GameObject*>& objects){

	//プレイヤーOBB　セット
	OrientedBoundingBox p_obb = player->player_obb();

	auto itr = objects.begin();
	OrientedBoundingBox box_obb;

	while (itr != objects.end()){

		//段ボールOBBを取得

		//OBBサイズ
		box_obb = (*itr)->GetOBB();

		box_obb.Radius.x *= 1.0f;
		box_obb.Radius.y *= 4.0f;
		box_obb.Radius.z *= 1.0f;

		//プレイヤーと段ボール　衝突判定
		if (p_obb.Intersects(box_obb))
		{
			Visitor* visitor = this->CreateVisitor((*itr));
			if (visitor == nullptr) continue;
			this->postMethod_(visitor);
			delete visitor;
			itr = objects.erase(itr);
			continue;
		}

		itr++;

	}

}

/**
 * @fn プレイヤーの受付
 * @param player　playerクラスのポインタ
 */
void OBBcheck::EntryPlayer(Player* player){

	this->player = player;
	
}

/**
 * @fn 敵VisitorFactoryクラスの呼び出し
 * @param postMethod　playerクラスのポインタ
 */
void OBBcheck::EntryVisitorPostMethod(std::function<void(Visitor*)> postMethod){

	this->postMethod_ = postMethod;

}

Visitor* OBBcheck::CreateVisitor(GameObject* object){
	
	// クラスのIDをもとに対応するVisitorを生成する

	if (typeid(*object) == typeid(Cardboard_Box))
		return BreakBox_Visitor_Factory().factoryMethod(object);

	if (typeid(*object) == typeid(Cardboard_Chip))
	{
		return BreakChip_Visitor_Factory().factoryMethod(object);
	}

	if (typeid(*object) == typeid(Enemy))
	{
	/*	player SetState(DAMAGE);*/
		return PlayerAttackCheck(object);
	}


	return nullptr;

}


Visitor* OBBcheck::PlayerAttackCheck(GameObject* object){

	if (player->IsAttack()) return BreakEnemy_Visitor_Factory().factoryMethod(object);
	return DamagePlayer_Visitor_Factory().factoryMethod(object);

}