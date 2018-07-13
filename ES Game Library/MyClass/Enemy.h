/**
 * @file   Enemy.h
 * @brief  �G�N���X�w�b�_�[�t�@�C��
 * @author reo okuhama
 * @date   2018/6/30
 */

#pragma once
#include "../ESGLib.h"
#include "AnimationObject.h"

/**
 * �G�N���X
 */
class Enemy : public AnimationObject
{
public:

	enum MOVESTATE{
		MOVE_DROP,
		MOVE_FORWARD
	};

	Enemy(ANIMATIONMODEL);
	~Enemy();

	virtual bool initialize(Vector3);
	virtual int Update();
	virtual void Draw();

	void Used();
	bool Get_use_flag(){ return use_flag; }

	MOVESTATE Get_state();
	void Set_state(MOVESTATE);

private:

	bool use_flag;
	MOVESTATE state;
};

