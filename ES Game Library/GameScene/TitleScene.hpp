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
	// 変数宣言
	SPRITE title;

	/*タイトル画面で1分以上放置されたらデモムービーを流す*/
	int demo_count;

	/*ゲームパッドのボタンが押されているか調べる*/
	bool GamePadButtonState();

	//ゲームパッドステート、バッファ宣言
	GamePadState    pad_state;
	GamePadBuffer   pad_buffer;

	int keep_timer;
	
	// 関数プロトタイプ

};
