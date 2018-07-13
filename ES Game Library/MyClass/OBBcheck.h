/**
 * @file   OBBcheak.h
 * @brief  �R���W�����N���X�w�b�_�[�t�@�C��
 * @author reo okuhama
 * @date   2018/6/12
 */ 

#pragma once 
#include "../ESGLib.h"
#include <vector>
#include <map>
#include <functional>

/**
 *  Player�N���X
 */
class Player;

/**
 *  Field�N���X
 */
class Fieldr;

/**
 * GameObject�N���X
 */
class GameObject;

/**
 *  Visitor�N���X
 */
class Visitor;

/**
 * Vizitor_Factory�N���X
 */
class Visitor_Factory;

/**
 * �R���W�����N���X
 */
class OBBcheck
{

public:
	OBBcheck();
	~OBBcheck();

	void Update(std::vector<GameObject*>& boxes);
	void EntryPlayer(Player*);

	void EntryVisitorPostMethod(std::function<void(Visitor*)> postMethod);

private:

	Visitor* CreateVisitor(GameObject* object);

	Player* player;
	std::function<void(Visitor*)> postMethod_;

	Visitor* PlayerAttackCheck(GameObject* object);
};