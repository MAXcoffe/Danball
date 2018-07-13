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

    //ゲームパッドステート、バッファ宣言
	GamePadState    pad_state;
	GamePadBuffer   pad_buffer;
	
	//player座標取得
	Vector3 player_pos;
	
	//player正面取得
	Vector3 front_vec;

	// ノックバック処理
	bool	knockback_state;
	Vector3	knockback_dir;
	Vector3	knockback_speed;
	float	knockback_speed_max;

	// ノックバック方向転換		
	Vector3 target;
	Matrix  dir;
	bool	player_dir_state;

	//アニメーションステート
	int animation_state;

	//アニメーションカウント
	int count;

	//プレイヤー座標
	float playyer_x,playyer_y,playyer_z;

	//player加速度
	int acc_time;

	//player 実際の速さ
	float fact;

	//player speed  state
	int speed_state;

	//playerエフェクト
	
	//頭
	ANIMATIONMODEL head;
	float   head_frame;
	//足

	//衝突

	
};

