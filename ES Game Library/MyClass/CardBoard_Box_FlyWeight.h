/**
 * @file   CardBoard_Box_FlyWeight.h
 * @brief  段ボールbox FlyWeightクラスヘッダーファイル
 * @author reo okuhama
 * @date   2018/7/2
 */

#pragma once
#include "../ESGLib.h"
#include <vector>

/**
* @file   Cardboard_Box.h
* @brief  段ボールboxクラスヘッダーファイル
* @author reo okuhama
* @date   2018/6/16
*/
class Cardboard_Box;

/**
 * @brief  段ボールboxクラスヘッダーファイル
 */
class CardBoard_Box_FlyWeight
{
public:
	
	~CardBoard_Box_FlyWeight();
	static CardBoard_Box_FlyWeight& GetInstance(){
	
		static CardBoard_Box_FlyWeight Instance;
		return Instance;

	}

	Cardboard_Box* GetCardboard_Box(Vector3 pos);
	void UsedCardboard_Box(Cardboard_Box*);

private:

	CardBoard_Box_FlyWeight();
	std::vector<Cardboard_Box*> boxes;
	MODEL model;

};




