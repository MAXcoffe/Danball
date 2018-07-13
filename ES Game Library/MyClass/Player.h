#pragma once
#include "../ESGLib.h"
#include "../StdAfx.h"
#include "Acceptor.h"
#include <stdio.h>



class Player : public Acceptor
{
public:
	Player();
	~Player();
	
	virtual bool Initialize();
	virtual int  Update();
	int  Effect();
	void Move();
	void Draw();

	virtual void Accept(Visitor* visitor);
	OrientedBoundingBox player_obb(){ 
		
		OrientedBoundingBox obb = player->GetOBB();
		obb.Center.x += 10.0f;
		obb.Center.y -= 10.0f;
		obb.Center.z += 10.0f;
		
		return  obb;
	}



	void Add_speeed();
	bool IsAttack();
	bool IsDamage();

private:

	ANIMATIONMODEL player;
	MODEL debug_box_;
	
	enum PLAYER_ANIMATION {
		ATTACK_HIGH,
		ATTACK_LOW,
		DAMAGE,
		WALK,
		STOP,
		ANIMATION_MAX
	};

    //�Q�[���p�b�h�X�e�[�g�A�o�b�t�@�錾
	GamePadState    pad_state;
	GamePadBuffer   pad_buffer;
	
	//player���W�擾
	Vector3 player_pos;
	
	//player���ʎ擾
	Vector3 front_vec;

	// �m�b�N�o�b�N����
	bool	knockback_state;
	Vector3	knockback_dir;
	Vector3	knockback_speed;
	float	knockback_speed_max;

	// �m�b�N�o�b�N�����]��		
	Vector3 target;
	Matrix  dir;
	bool	player_dir_state;

	//�A�j���[�V�����X�e�[�g
	int animation_state;

	//�A�j���[�V�����J�E���g
	int count;

	//�v���C���[���W
	float playyer_x,playyer_y,playyer_z;

	//player�����x
	int acc_time;

	//player ���ۂ̑���
	float fact;

	//player speed  state
	int speed_state;

	//player�G�t�F�N�g
	
	//��
	ANIMATIONMODEL head;
	float   head_frame;
	//��

	//�Փ�

	
};

