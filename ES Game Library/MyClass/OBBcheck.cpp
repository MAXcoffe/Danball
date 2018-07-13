/**
* @file   OBBcheck.cpp
* @brief  �R���W�����`�F�b�N�N���Xcpp�t�@�C��
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
 * @fn �R���X�g���N�^
 */
OBBcheck::OBBcheck(){

}

/**
 * @fn �f�X�g���N�^
 */
OBBcheck::~OBBcheck(){



}


/**
 * @fn ����
 * @return 0...����I�� / 0�ȊO...�ُ�I��
 */
void OBBcheck::Update(std::vector<GameObject*>& objects){

	//�v���C���[OBB�@�Z�b�g
	OrientedBoundingBox p_obb = player->player_obb();

	auto itr = objects.begin();
	OrientedBoundingBox box_obb;

	while (itr != objects.end()){

		//�i�{�[��OBB���擾

		//OBB�T�C�Y
		box_obb = (*itr)->GetOBB();

		box_obb.Radius.x *= 1.0f;
		box_obb.Radius.y *= 4.0f;
		box_obb.Radius.z *= 1.0f;

		//�v���C���[�ƒi�{�[���@�Փ˔���
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
 * @fn �v���C���[�̎�t
 * @param player�@player�N���X�̃|�C���^
 */
void OBBcheck::EntryPlayer(Player* player){

	this->player = player;
	
}

/**
 * @fn �GVisitorFactory�N���X�̌Ăяo��
 * @param postMethod�@player�N���X�̃|�C���^
 */
void OBBcheck::EntryVisitorPostMethod(std::function<void(Visitor*)> postMethod){

	this->postMethod_ = postMethod;

}

Visitor* OBBcheck::CreateVisitor(GameObject* object){
	
	// �N���X��ID�����ƂɑΉ�����Visitor�𐶐�����

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