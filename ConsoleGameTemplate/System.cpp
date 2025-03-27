#include "System.h"
#include "ConsoleGameTemplate.cpp"

System Setting;

	void System::SceneInit()
	{
		consoleRender::ScreenInit();
		
		GetSceneType(SceneCurrent); // 현재 씬을 가져온다.
		
	}
	
	void System::SceneUpdate()
	{
		if (Input::IsKeyDown(true))
		{
			SceneType nextScene;							// 다음 씬 저장  변수 4byte

			SetSceneType(SceneCurrent);						// 현재 씬을 지정한다. 
															
			if (!SceneCurrent)								// 현재 씬이 아닐 때 
			{
				nextScene = NextChangeIndex(SceneCurrent);
				ChangeScene(SceneCurrent);
			}

			else if (GetSceneType(SceneCurrent) == SceneType::PLAY)
			{
				// 다음씬은 현재씬의 다음씬을 준비 시킨 함수의 리턴 값으로 지정 
				// 다음 씬이 준비되었을 때 현재 씬에 따라서  다음 씬으로 변경해야 한다. 
				nextScene = NextChangeIndex(SceneCurrent);
				ChangeScene(SceneCurrent);
			}
			else if (GetSceneType(SceneCurrent) == SceneType::END && g_bQuit == true )
			{
				printf("게임을 종료합니다.");
			} 
		}
	}
	
	void System::SceneRender()
	{
		consoleRender::ScreenClear();
	
		char* buf = { 0, }; 
		consoleRender::ScreenDrawString(0, 0, buf, FG_PINK_DARK);
	
		// 현재 씬을 가져와 변경한다.
		ChangeScene(GetSceneType(SceneCurrent));
		
		// 현재 씬을 출력 
		consoleRender::ScreenFlipping();

		delete Setting.map; 
	}
	
	void System::ChangeScene(SceneType sceneCurrent)
	{
		SetSceneType(sceneCurrent);
	
		switch (sceneCurrent) // 현재 씬을 대상으로, 
		{
			// 메뉴, 플레이, 엔딩 일 때의 케이스 
		case SceneType::MENU:
			menu.MenuRender();
			break;

		case SceneType::PLAY:
			play.Render();
			break;

		case SceneType::END:
			
			break;
		}
	}
	System::SceneType System::NextChangeIndex(SceneType scenecurrent)
	{
		GetSceneType(scenecurrent);

		if (SceneCurrent == NULL)
		{
			printf("현재 씬은 비어있습니다.");
			return;
		}
	
		// 다음 씬으로 변경할 값 증감 
		// 현재 씬은 enum 으로 관리하고 있기 때문에 , MENU : 0, PLAY : 1, END : 2 로 정수로 관리가 가능하기 때문에 NextIndex를 현재 씬으로 초기화 .
		// 증감 조건은 NextIndex 가 두번 증가하는 걸 방지하기 위해 존재 하지 않는다. 
		for (int NextIndex = scenecurrent; NextIndex <= 3; )
		{
			return NextScene[NextIndex++];
		}

	}
	


	void System::ProcessInput()
	{
		if (Input::IsKeyDown(VK_LEFT)) { //왼쪽
			g_Player.X--;
		}
		else if (Input::IsKeyDown(VK_RIGHT)) { //오른쪽
			g_Player.X++;
		}
		else if (Input::IsKeyDown(VK_UP)) { //위
			g_Player.Y--;
		}
		else if (Input::IsKeyDown(VK_DOWN)) { //아래
			g_Player.Y++;
		}
		else if (Input::IsKeyDown(VK_ESCAPE)) { //종료
			g_bQuit = true;
		}
		if (Setting.SceneCurrent == Setting.SceneType::MENU && getchar())
		{
			Setting.ChangeScene(Setting.SceneCurrent); 
			Setting.NextChangeIndex(Setting.SceneCurrent); 
		}
	
	}
	
