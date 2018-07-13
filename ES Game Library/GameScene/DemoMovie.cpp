#include "DemoMovie.hpp"
#include "TitleScene.hpp"
#include "GameScene.hpp"
#include <stdio.h>


/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load any non-graphic
/// related content.  Calling base.Initialize will enumerate through any components
/// and initialize them as well.
/// </summary>
bool DemoMovie::Initialize()
{
	// TODO: Add your initialization logic here
	demo = MediaManager.CreateMediaFromFile(_T("DEMO\\pvTrim.wmv"));

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void DemoMovie::Finalize()
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
int DemoMovie::Update()
{
	// TODO: Add your update logic here
	demo->Play();
	if (demo->IsComplete())
			demo->Replay();
	return 0;
}



/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void DemoMovie::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();

	SpriteBatch.Begin();
	SpriteBatch.Draw(*demo, Vector3_Zero, 1.0f, Vector3_Zero, Vector3_Zero, 1280.0f / 1920.0f);
	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
