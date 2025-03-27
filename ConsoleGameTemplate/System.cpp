#include "System.h"
#include "ConsoleGameTemplate.cpp"

System Setting;

	void System::SceneInit()
	{
		consoleRender::ScreenInit();
		
		GetSceneType(SceneCurrent); // ���� ���� �����´�.
		
	}
	
	void System::SceneUpdate()
	{
		if (Input::IsKeyDown(true))
		{
			SceneType nextScene;							// ���� �� ����  ���� 4byte

			SetSceneType(SceneCurrent);						// ���� ���� �����Ѵ�. 
															
			if (!SceneCurrent)								// ���� ���� �ƴ� �� 
			{
				nextScene = NextChangeIndex(SceneCurrent);
				ChangeScene(SceneCurrent);
			}

			else if (GetSceneType(SceneCurrent) == SceneType::PLAY)
			{
				// �������� ������� �������� �غ� ��Ų �Լ��� ���� ������ ���� 
				// ���� ���� �غ�Ǿ��� �� ���� ���� ����  ���� ������ �����ؾ� �Ѵ�. 
				nextScene = NextChangeIndex(SceneCurrent);
				ChangeScene(SceneCurrent);
			}
			else if (GetSceneType(SceneCurrent) == SceneType::END && g_bQuit == true )
			{
				printf("������ �����մϴ�.");
			} 
		}
	}
	
	void System::SceneRender()
	{
		consoleRender::ScreenClear();
	
		char* buf = { 0, }; 
		consoleRender::ScreenDrawString(0, 0, buf, FG_PINK_DARK);
	
		// ���� ���� ������ �����Ѵ�.
		ChangeScene(GetSceneType(SceneCurrent));
		
		// ���� ���� ��� 
		consoleRender::ScreenFlipping();

		delete Setting.map; 
	}
	
	void System::ChangeScene(SceneType sceneCurrent)
	{
		SetSceneType(sceneCurrent);
	
		switch (sceneCurrent) // ���� ���� �������, 
		{
			// �޴�, �÷���, ���� �� ���� ���̽� 
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
			printf("���� ���� ����ֽ��ϴ�.");
			return;
		}
	
		// ���� ������ ������ �� ���� 
		// ���� ���� enum ���� �����ϰ� �ֱ� ������ , MENU : 0, PLAY : 1, END : 2 �� ������ ������ �����ϱ� ������ NextIndex�� ���� ������ �ʱ�ȭ .
		// ���� ������ NextIndex �� �ι� �����ϴ� �� �����ϱ� ���� ���� ���� �ʴ´�. 
		for (int NextIndex = scenecurrent; NextIndex <= 3; )
		{
			return NextScene[NextIndex++];
		}

	}
	


	void System::ProcessInput()
	{
		if (Input::IsKeyDown(VK_LEFT)) { //����
			g_Player.X--;
		}
		else if (Input::IsKeyDown(VK_RIGHT)) { //������
			g_Player.X++;
		}
		else if (Input::IsKeyDown(VK_UP)) { //��
			g_Player.Y--;
		}
		else if (Input::IsKeyDown(VK_DOWN)) { //�Ʒ�
			g_Player.Y++;
		}
		else if (Input::IsKeyDown(VK_ESCAPE)) { //����
			g_bQuit = true;
		}
		if (Setting.SceneCurrent == Setting.SceneType::MENU && getchar())
		{
			Setting.ChangeScene(Setting.SceneCurrent); 
			Setting.NextChangeIndex(Setting.SceneCurrent); 
		}
	
	}
	
