#pragma once

#include "ESGLib.h"
#include "GameScene/GameScene.hpp"
#include "MyClass/Field.h"
#include "MyClass/Player.h"
#include "MyClass/FieldItem.h"
#include "MyClass/Box_Manager.h"
#include "MyClass/Cardboard_Box.h"
#include "MyClass\Box_Manager.h"
#include "MyClass\Chip_Manager.h"
#include "MyClass\OBBcheck.h"
#include "MyClass\Cardboard_Chip.h"
#include "MyClass\EnemyManager.h"
#include "MyClass\Score.h"

class GameMain : public CGameScene {
public:
	GameMain() : DefaultFont(GraphicsDevice.CreateDefaultFont())
	{
//		ContentRootDirectory(_T("Content"));
	}

	virtual ~GameMain()
	{
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

		Finalize();
	}

public:
	virtual bool Initialize();

	virtual int  Update();
	virtual void Draw();

private:
	void Finalize();
	FONT DefaultFont;

private:
	// ïœêîêÈåæ
	// ÉNÉâÉX
	Field field;
	Player player;
	Camera camera;
	FieldItem map_item;
	Box_Manager box_manager;
	Chip_Manager chip_manager;
	OBBcheck obb_check;
	EnemyManager enemy_manager;
	Score score;

	MUSIC bgm;

	std::vector<Acceptor*>	acceptors_;

	float camera_x , camera_y , camera_z ;

	// ä÷êîêÈåæ

};
