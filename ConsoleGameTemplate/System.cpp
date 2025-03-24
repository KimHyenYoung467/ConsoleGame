#include "System.h"

void GManager::Initialize()
{
	// ���� ��ũ���� ���� ���� ������ 
	ConsoleRenderer::ScreenWidth();
	ConsoleRenderer::ScreenHeight();

	// ���� ��ũ�� ���� 
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

