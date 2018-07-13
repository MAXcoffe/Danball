/**
* @file   CardBoard_Box_FlyWeight.h
* @brief  �i�{�[����FlyWeight�N���X
* @author reo okuhama
* @date   2018/7/2
*/

#include "CardBoard_Box_FlyWeight.h"
#include "Cardboard_Box.h"

/**
* @fn �R���X�g���N�^
* @param model 3D���f��
*/
CardBoard_Box_FlyWeight::CardBoard_Box_FlyWeight(){

	model = GraphicsDevice.CreateModelFromFile(_T("GAME_ITEM\\dan_box.X"));
	model->SetScale(0.25f);

}

/**
* @fn �f�X�g���N�^
*/
CardBoard_Box_FlyWeight::~CardBoard_Box_FlyWeight(){



}

/**
 * @fn ����
 * @param pos          Cardboard_Box���������Ă������W
 * @param Get_use_flag use_flag���擾���邽�߂̊֐�
 * @return true...���� / false...���s
 */
Cardboard_Box* CardBoard_Box_FlyWeight::GetCardboard_Box(Vector3 pos){

	//�g���ĂȂ��̂����邩�T��
	for (auto box : boxes)
	{
		//���g�p�ł����
		if (!box->Get_use_flag())
		{
			//��������
			box->initialize(pos);
			//�ė��p
			return box;
		}

	}

	//�����܂ŗ����ꍇ�͂��ׂĎg�p�ς݂Ȃ̂�
	//�������A
	Cardboard_Box* cardboard_box = new Cardboard_Box(this->model);
	//�z��ɂԂ�����
	boxes.push_back(cardboard_box);
	//�������̏�
	cardboard_box->initialize(pos);
	//���p
	return cardboard_box;

}

/**
 * @fn  box���g���Ă��邩
*/
void CardBoard_Box_FlyWeight::UsedCardboard_Box(Cardboard_Box* use_cardboard_box){

	use_cardboard_box->Used();

}