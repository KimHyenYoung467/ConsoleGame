#pragma once
#include <Windows.h>
#include "Input.h"
#include "Time.h"
#include "ConsoleRenderer.h"
#include "PLAY.h"
#include "System.h"
#include <stdio.h>
#include "ConsoleGameTemplate.cpp"


namespace GManager
{
	enum struct SceneType { MENU, PLAY, END };

	COORD S_Player = { 0, }; // �÷��̾� ��ġ�� ���� 

	SceneType SceneCurrent;		// ���� �� 
	SceneType* SceneNext;	    // ���� �� 
	bool isRunning;

	SHORT prevState = 0;
	void Initialize(); 

	void ChangeScene(SceneType newScene); // ��Ȳ(�Է� �Ǵ� �ð� ����) �� ���� SceneNext ���� 
	void Update();						  // 
	void Render();						  // �ܼ�â�� �ؽ�Ʈ�� �׸��� 
	bool IsRunning() { return isRunning; };

}
