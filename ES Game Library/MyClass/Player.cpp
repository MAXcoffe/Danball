#include "Player.h"
#include "Field.h"
#include "Visitor.h"

Player::Player()
{
}



Player::~Player()
{
}

bool Player::Initialize()
{
	//player初期化
	player = GraphicsDevice.CreateAnimationModelFromFile(_T("PLAYER\\player.X"));
	player->SetPosition(Vector3_Zero);
	player->SetScale(0.2f);

	OrientedBoundingBox obb = player->GetOBB();

	SimpleShape   box_shape;
	box_shape.Type = Shape_Box;
	box_shape.Width = obb.Radius.x * 3.0f;
	box_shape.Height = obb.Radius.y * 3.0f;
	box_shape.Depth = obb.Radius.z * 3.0f;
	debug_box_ = GraphicsDevice.CreateModelFromSimpleShape(box_shape);

	//playerアニメーション初期化
	animation_state = WALK;
	
	player->SetTrackEnable(WALK, TRUE);
	player->SetTrackEnable(DAMAGE, FALSE);
	player->SetTrackEnable(ATTACK_HIGH,FALSE);
	player->SetTrackEnable(ATTACK_LOW, FALSE);
	player->SetTrackEnable(STOP, FALSE);

	//player座標取得
	Vector3 player_pos = player->GetPosition();
	
	//player正面取得
	Vector3 front_vec = player->GetFrontVector();

	//プレイヤー加速度　初期化
	acc_time = 0;

	//playerエフェクト初期化
	//頭
	head = GraphicsDevice.CreateAnimationModelFromFile(_T("EFFECT\\kemuri.X"));
	head->SetRotation(180.0f, 0.0, 180.0f);
	head->SetScale(0.1);
	//足

	//衝突
	return true;
}



int Player::Update()
{
	switch (animation_state) {
	

//歩きの時-----------------------------------------------------------------------------------
	case WALK:{
	    if (pad_buffer.IsPressed(GamePad_Button4)) {

			////animation_state == ATTACK_HIGH;
			
			fact = 0.5f;
			player->SetTrackEnable(WALK, FALSE);
			player->SetTrackEnable(ATTACK_HIGH, TRUE);
			player->SetTrackEnable(ATTACK_LOW, FALSE);
			player->SetTrackEnable(DAMAGE, FALSE);
			player->SetTrackEnable(STOP, FALSE);
			
			if (animation_state = ATTACK_HIGH)
			{
				//ゲームパッドを正面以外操作不能
				animation_state = STOP;
			}
		}
	}break;
//---------------------------------------------------------------------------------------
	 
//ダメージ処理---------------------------------------------------------------------------
		case DAMAGE:
		{
			if (player->GetTrackPosition(DAMAGE) > 0.60)
			{
				player->SetTrackEnable(DAMAGE, TRUE);

				if (count < 0.016)
				{
					animation_state = WALK;
					player->SetTrackEnable(WALK, TRUE);
					player->SetTrackEnable(ATTACK_LOW, FALSE);
					player->SetTrackEnable(ATTACK_HIGH, FALSE);
					player->SetTrackEnable(STOP, FALSE);
					player->SetTrackEnable(DAMAGE, FALSE);
					player->SetTrackPosition(DAMAGE, 0.0);

				}
			}

		} break;
//---------------------------------------------------------------------------------------

//攻撃弱の時-----------------------------------------------------------------------------
		case ATTACK_LOW:
		{

		} break;
//---------------------------------------------------------------------------------------

//攻撃強の時-----------------------------------------------------------------------------
		case ATTACK_HIGH:
		{
			if (player->GetTrackPosition(ATTACK_HIGH) > 0.60)
			{
				//硬直ステートをTRUE
				animation_state = STOP;
				
				player->SetTrackEnable(STOP, TRUE);
				

				player->SetTrackPosition(ATTACK_LOW, 0.0);

				if (count < 0.016)
				{
					animation_state = WALK;
					player->SetTrackPosition(ATTACK_LOW, 0.0);
					player->SetTrackEnable(WALK, TRUE);
					player->SetTrackEnable(ATTACK_LOW, FALSE);
					player->SetTrackEnable(ATTACK_HIGH, FALSE);
					player->SetTrackEnable(STOP, FALSE);
					player->SetTrackEnable(DAMAGE, FALSE);
					player->SetTrackPosition(ATTACK_HIGH, 0.0);

				}
			}
			
		} break;
//---------------------------------------------------------------------------------------

//硬直状態-------------------------------------------------------------------------------
		case STOP:
		{
			//時間測る　一定時間立ったらWALK
			//count[x]++;
			//if (count[x] >= 50)
			//{
			//	player_state[x] = WALK;
			//	player[x]->SetTrackEnable(WALK   , TRUE);
			//	count[x] = 0;
	  //          acc_time[x] = 0;
		 //       fact[x] = 2.0f;
			//} 

			//else if(count[x] < 50){

			//	player[x]->Move(0.0f, 0.0f, 0.0f);/*Vector3(player[x]->GetFrontVector());*/

			//	player[x]->SetTrackEnable(WALK   , FALSE);
			//	player[x]->SetTrackEnable(ATTACK1, FALSE);
			//	player[x]->SetTrackEnable(ATTACK2, FALSE);
			//	player[x]->SetTrackEnable(STOP, FALSE);
			//	player[x]->SetTrackEnable(DAMAGE , FALSE);
			//	

	

			//} 
		}
		break;
//---------------------------------------------------------------------------------------
	}





	return 0;
}

int Player::Effect()
{
    
	if (head_frame >= 5.0f)
		head_frame = 0.0f;
	return 0;
}

void Player::Move()
{
	//キーボードを取得
		KeyboardBuffer  key_buffer = Keyboard->GetBuffer();

		//ゲームパッドステート、バッファを取得
		pad_state = GamePad(0)->GetState();
		pad_buffer = GamePad(0)->GetBuffer();

		//操作
		const float   X_RATIO = (float)pad_state.X / (float)Axis_Max;
		const float   Y_RATIO = (float)pad_state.Y / (float)Axis_Max;

		//プレイヤー座標の取得
		Vector3 player_pos = player->GetPosition();

		if (pad_state.X == 0 && pad_state.Y == 0){
			acc_time = 0;
			return;
		}
			//プレイヤーの正面の向きを取得
			Vector3 old_front = player->GetFrontVector();

			//回転方向
			const float DISTANCE = Math_Sqrt(X_RATIO * X_RATIO + Y_RATIO * Y_RATIO * 1.05f);
			const float ANGLE = MathHelper_Atan2(X_RATIO, -Y_RATIO);
			float min_distance = FLT_MAX, distance = FLT_MAX;
			player->SetDirection(0.0f, ANGLE, 0.0f);



			// 移動方向設定	
			Vector3 front_vec = player->GetFrontVector();
			float cos_theta = Vector3_Dot(front_vec, old_front);

			front_vec = Vector3_Normalize(front_vec);
			player->SetDirection(0.0f, MathHelper_Atan2(front_vec.x, front_vec.z), 0.0f);
	

			//加速度　
			acc_time++;

			//加速3 
			if (acc_time >= GameTimer.GetFPS() * 3)
				fact = 2.0f;
			//加速2
			else if (acc_time >= GameTimer.GetFPS() * 1)
				fact = 1.0f;
			//加速1
			else
				fact = 0.5f;
			
			//移動の速さ
			player->Move(0.0f, 0.0f, 0.5 * fact);

		
}



void Player::Add_speeed(){

	acc_time++;

}



void Player::Draw()
{
	player->AdvanceTime(0.016);
	player->Draw();
	head->Draw();
	

	Vector3 pos = player->GetPosition();
	head->SetPosition(pos.x, pos.y + 15, pos.z);
	
    //アニメーションの速さ
	head->AdvanceTime(0.0016);


	head->DrawAlpha(1.0);
	//アニメーションアルファブレンドモード

	OrientedBoundingBox obb = this->player_obb();

	//デバック　あたり判定
	debug_box_->SetPosition(obb.Center + Vector3(10.0f,0.0f,10.0f));
	debug_box_->Draw();
}

void Player::Accept(Visitor* visitor){

	visitor->Visit(this);

}

bool Player::IsAttack(){

	return animation_state == ATTACK_HIGH ;

}

bool Player::IsDamage(){

	return animation_state == DAMAGE;

}