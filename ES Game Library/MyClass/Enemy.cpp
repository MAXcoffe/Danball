/**
* @file   Enemy.cpp
* @brief  �G�N���Xcpp�t�@�C��
* @author reo okuhama
* @date   2018/6/30
*/

#include "Enemy.h"
#include "Visitor.h"
#include <random>
#include "AnimationObject.h"

/**
 * @fn �R���X�g���N�^
 * @param use_flag �g�p��
 * @param state    ���
 */
Enemy::Enemy(ANIMATIONMODEL model) : AnimationObject(model)
{
	use_flag = false;
	state = MOVE_DROP;

}

/**
 * @fn �f�X�g���N�^
 */
Enemy::~Enemy()
{
}

/**
 * @fn ������
 * @param (pos) �@ �������W
 * @param state    ���
 * @param use_flag �g�p��
 * @return true...���� / false...���s
 */
bool Enemy::initialize(Vector3 pos){

	this->pos_ = pos;
	state = MOVE_DROP;
	use_flag = true;

	return true;
}

/**
* @fn ����
* @return 0...����I�� / 0�ȊO...�ُ�I��
*/
int Enemy::Update(){

	switch (this->state){
	//������
	case (MOVE_DROP):{

		pos_.y -= 2.0f;

		} break;
	
	//��O
		case(MOVE_FORWARD) : {

			pos_.z -= 0.5f;

		}break;
	}

	return 0;

}

/**
�@* @fn �Q�b�^�[
�@* @preturn state ��� 
�@*/
Enemy::MOVESTATE Enemy::Get_state(){
	return state;
} 

/**
�@* @fn �Z�b�^�[
  * @preturn state ���
  * @pmove_state   �����Ă��� 
  */
void Enemy::Set_state(MOVESTATE move_state){

	this->state = move_state;

}

/**
* @fn �`��
* @param AdvanceTime �A�j���[�V�������x
* @param SetPosition ���W�ݒ�
*/
void  Enemy::Draw(){

	animation_model->SetPosition(pos_);
	animation_model->AdvanceTime(0.016);
	animation_model->Draw();

}

/**
 * @fn �@�@�@�@�@ �g�p���
 * @puse_flag �@�@�g�p��
 * @pmove_state   �����Ă���
 */
void Enemy::Used(){ use_flag = false; }