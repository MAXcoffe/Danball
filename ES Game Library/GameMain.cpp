// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"
#include <functional>

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ダンボールバトル"));

	//クラスInitialize

	field.Initialize();
	player.Initialize();
	map_item.Initialize();
	box_manager.Initialize();
	chip_manager.Initialize();
	obb_check.EntryPlayer(&player);
	score.Initialize();

	acceptors_.push_back(&box_manager);
	acceptors_.push_back(&chip_manager);
	acceptors_.push_back(&score);

	auto notice = [&](Visitor* visitor){

		for (auto acceptor : acceptors_){

			acceptor->Accept(visitor);

		}
	};

	obb_check.EntryVisitorPostMethod(notice);
	enemy_manager.EntryVisitorPostMethod(notice);

	//BGM再生
	bgm = SoundDevice.CreateMusicFromFile(_T("BGM//BGM.wav"));
	/*bgm->Play();*/

	//ビューポート取得
	Viewport view = GraphicsDevice.GetViewport();
	//camera->SetPerspectiveFieldOfView(90.0f, (float)view.Width, (float)view.Height,1.0f, 1000.0f);;

	//カメラ初期座標
	camera_x = 0.0f;
	camera_y = 200.0f;
	camera_z = -145.0f;

	//カメラ
	camera->SetLookAt(Vector3(camera_x, camera_y, camera_z), Vector3(0.0f, 0.0f, 0.0f), Vector3_Up);
	camera->SetPerspectiveFieldOfView(55.0f, (float)view.Width, (float)view.Height, 1.0f, 10000.0f);
	GraphicsDevice.SetCamera(camera);

	//カメラポジション
	Vector3 camera_pos = camera->GetPosition();

	//ライト
	Light   light;
	light.Type = Light_Directional;
	light.Direction = Vector3_Forward + Vector3_Down;
	light.Diffuse = Color(Color_White);
	light.Ambient = Color(Color_White);
	light.Specular = Color(Color_White);
	light.Position = Vector3(camera_pos);

	GraphicsDevice.SetLight(light);

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	// TODO: Add your finalization logic here
}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.llllllllllllllllllll------------------
/// </returns>
int GameMain::Update()
{
	// TODO: Add your update logic here

	//クラスアップデート
	field.Update();
	player.Update();
	//map_item.Update();
	player.Move();
	box_manager.Update();
	chip_manager.Update();
	obb_check.Update(box_manager.GetBoxes());
	obb_check.Update(chip_manager.GetChips());
	obb_check.Update(enemy_manager.GetEnemys());
	enemy_manager.Update(field.get_model());
	score.Update();


	KeyboardState   key_state = Keyboard->GetState();

		if (key_state.IsKeyDown(Keys_Space)) {
			camera->Move(0.0f, 0.0f, 2.0f);
		}

		if (key_state.IsKeyDown(Keys_B)) {
			camera->Move(0.0f, 0.0f, -2.0f);
		}

		if (key_state.IsKeyDown(Keys_Right)) {
			camera->Rotation(0.0f, 1.0f, 0.0f);
		}

		if (key_state.IsKeyDown(Keys_Left)) {
			camera->Rotation(0.0f, -1.0f, 0.0f);
		}
		if (key_state.IsKeyDown(Keys_Down)) {
			camera->Rotation(-1.0f, 0.0f, 0.0f);
		}

		if (key_state.IsKeyDown(Keys_Up)) {
			camera->Rotation(1.0f, 0.0f, 0.0f);
		}

		//カメラ
		GraphicsDevice.SetCamera(camera);

	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();

	//クラスDraw
	map_item.Draw();
	box_manager.Draw();
	chip_manager.Draw();
	enemy_manager.Draw();
	score.Draw();
	//AlphaBlendで描画

	GraphicsDevice.BeginAlphaBlend();
	/*DrawAlpha_BackFace;*/field.Draw();
	player.Draw();

	GraphicsDevice.EndAlphaBlend();
	


	GraphicsDevice.EndScene();
}
