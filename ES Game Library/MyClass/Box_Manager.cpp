#include "Box_Manager.h"
#include "field.h"
#include "Visitor.h"
#include "Cardboard_Box.h"
#include "CardBoard_Box_FlyWeight.h"

Box_Manager::Box_Manager()
{
	
	

}


Box_Manager::~Box_Manager()
{

	//�f�[�^�̉����FlyWeight������Ă����̂łȂ�

}

bool Box_Manager::Initialize()
{
	//�����_���֐��̏�����
	std::random_device seed;
	this->random_ = std::mt19937(seed());

    //�����_���͈̔͂��w��
	this->x_dist_ = std::uniform_real_distribution<float>(-50.0f, 50.0f);
	this->z_dist_ = std::uniform_real_distribution<float>(-50.0f, 50.0f);

	//�Q�[�������Ԃ�������
	keep_timer = 0;
	//�i�{�[�����Q�[���I�u�W�F�N�g�̔z��ɓ��ꍞ��
	this->boxes = std::vector<GameObject*>();

	return true;
}

int  Box_Manager::Update()
{
	//�Q�[�������Ԃ�5�b�o�ߖ��Ƀ����_���Ȉʒu�ɒi�{�[�����𐶐�
	this->keep_timer += GameTimer.GetElapsedMilliSecond();
	if (keep_timer >= 5000)
	{
		float x = this->x_dist_(this->random_);
		float z = this->z_dist_(this->random_);

		//������FlyWeight(Box)����f�[�^��������Ă���
		Cardboard_Box* box = CardBoard_Box_FlyWeight::GetInstance().GetCardboard_Box(Vector3(x,0.0f,z));
		//���������i�{�[���̔z��̍Ō�ɓ��ꍞ��
		this->boxes.push_back(box);
		//�Q�[�������Ԃ�-5�b
		this->keep_timer -= 5000;
 	}


	return 0;
}
void Box_Manager::Draw()
{
	//�i�{�[����`��
	for (auto box : boxes)
	{
		box->Draw();
	}
}

//Visitor�̎󂯓���
void Box_Manager::Accept(Visitor* visitor){

	visitor->Visit(this);

}