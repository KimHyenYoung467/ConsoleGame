#include "System.h"

void GManager::Initialize()
{
	// 현재 스크린의 가로 세로 얻어오기 
	ConsoleRenderer::ScreenWidth();
	ConsoleRenderer::ScreenHeight();

	// 현재 스크린 설정 
	ConsoleRenderer::ScreenInit();
}

void GManager::ChangeScene(SceneType newScene)
{
	switch (newScene)
	{
	case SceneType::MENU:
		Input::IsKeyDown(1); 
		SceneCurrent = SceneType::MENU;
		break;
	case SceneType::PLAY:
		SceneCurrent = SceneType::PLAY;
		break;
	case SceneType::END:
		SceneCurrent = SceneType::END;
		isRunning = false;
		break;
	}
	SceneNext = &newScene;
	ChangeScene(*SceneNext);
}
void GManager::Update()
{
	if (Input::IsKeyDown(true))
	{
		SceneType nextScene = SceneCurrent;

		if (nextScene != SceneCurrent)
		{
			ChangeScene(nextScene);
		}
	}
}

void GManager::Render()
{
	ConsoleRenderer::ScreenClear();

	char* buf = { 0, }; 
	ConsoleRenderer::ScreenDrawString(0, 0, buf, FG_PINK_DARK);

	if (SceneCurrent == SceneCurrent)
	{
		ConsoleRenderer::ScreenFlipping();
	}
	
		
}

