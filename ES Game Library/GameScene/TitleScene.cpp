#include "../StdAfx.h"
#include "../GameScene/TitleScene.hpp"
#include "DemoMovie.hpp"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load any non-graphic
/// related content.  Calling base.Initialize will enumerate through any components
/// and initialize them as well.
/// </summary>
bool TitleScene::Initialize()
{
	// TODO: Add your initialization logic here
	title = GraphicsDevice.CreateSpriteFromFile(_T("SCENE\\Title.png"));
	keep_timer = 0;
	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void TitleScene::Finalize()
{
	// TODO: Add your finalization logic here

}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int TitleScene::Update()
{
	// TODO: Add your update logic here
	this->pad_state = GamePad(0)->GetState();

	this->keep_timer += GameTimer.GetElapsedMilliSecond();

	if (keep_timer <= 3000)
	{
		if (this->pad_state.Buttons[3] != 0)
		{
			return GAME_SCENE(new DemoMovie());
			keep_timer = -3000;
		}
		else
		{
			return GAME_SCENE(new GameMain());
		}
	}
}



/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void TitleScene::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();

	SpriteBatch.Begin();
	SpriteBatch.DrawSimple(*title, Vector3_Zero);
	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
