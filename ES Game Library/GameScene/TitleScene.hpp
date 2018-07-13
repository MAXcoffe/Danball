#pragma once

#include "GameScene.hpp"
#include "../ESGLib.h"
#include <stdio.h>

class TitleScene : public CGameScene {
public:
	TitleScene()
	{
		//		ContentRootDirectory(_T("Content"));
	}

	virtual ~TitleScene()
	{
		Finalize();

#ifdef _INC_SQUIRREL
		Squirrel.ReleaseAllScripts();
#endif
#ifdef _INC_NUI
		NUI.ReleaseAllKinects();
#endif
#ifdef _INC_LIVE2D
		Live2D.ReleaseAllModels();
#endif
#ifdef _INC_EFFEKSEER
		Effekseer.ReleaseAllEffects();
#endif
#ifdef _INC_DIRECT2D
		Direct2D.ReleaseAllResources();
#endif
		MediaManager.ReleaseAllMedia();

		SoundDevice.ReleaseAllMusics();
		SoundDevice.ReleaseAllSounds();

		GraphicsDevice.ReleaseAllRenderTargets();
		GraphicsDevice.ReleaseAllStateBlocks();
		GraphicsDevice.ReleaseAllFonts();
		GraphicsDevice.ReleaseAllSprites();
		GraphicsDevice.ReleaseAllAnimationModels();
		GraphicsDevice.ReleaseAllModels();
		GraphicsDevice.ReleaseAllVertexBuffers();
		GraphicsDevice.ReleaseAllEffects();
	}

	virtual bool Initialize();

	virtual int  Update();
	virtual void Draw();

private:
	void Finalize();

private:
	// �ϐ��錾
	SPRITE title;

	/*�^�C�g����ʂ�1���ȏ���u���ꂽ��f�����[�r�[�𗬂�*/
	int demo_count;

	/*�Q�[���p�b�h�̃{�^����������Ă��邩���ׂ�*/
	bool GamePadButtonState();

	//�Q�[���p�b�h�X�e�[�g�A�o�b�t�@�錾
	GamePadState    pad_state;
	GamePadBuffer   pad_buffer;

	int keep_timer;
	
	// �֐��v���g�^�C�v

};
