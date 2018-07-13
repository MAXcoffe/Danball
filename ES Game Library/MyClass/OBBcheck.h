/**
 * @file   OBBcheak.h
 * @brief  コリジョンクラスヘッダーファイル
 * @author reo okuhama
 * @date   2018/6/12
 */ 

#pragma once 
#include "../ESGLib.h"
#include <vector>
#include <map>
#include <functional>

/**
 *  Playerクラス
 */
class Player;

/**
 *  Fieldクラス
 */
class Fieldr;

/**
 * GameObjectクラス
 */
class GameObject;

/**
 *  Visitorクラス
 */
class Visitor;

/**
 * Vizitor_Factoryクラス
 */
class Visitor_Factory;

/**
 * コリジョンクラス
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