/**
 * @file   CardBoard_Box_FlyWeight.h
 * @brief  �i�{�[��box FlyWeight�N���X�w�b�_�[�t�@�C��
 * @author reo okuhama
 * @date   2018/7/2
 */

#pragma once
#include "../ESGLib.h"
#include <vector>

/**
* @file   Cardboard_Box.h
* @brief  �i�{�[��box�N���X�w�b�_�[�t�@�C��
* @author reo okuhama
* @date   2018/6/16
*/
class Cardboard_Box;

/**
 * @brief  �i�{�[��box�N���X�w�b�_�[�t�@�C��
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




