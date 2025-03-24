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

	COORD S_Player = { 0, }; // 플레이어 위치를 지정 

	SceneType SceneCurrent;		// 현재 씬 
	SceneType* SceneNext;	    // 다음 씬 
	bool isRunning;

	SHORT prevState = 0;
	void Initialize(); 

	void ChangeScene(SceneType newScene); // 상황(입력 또는 시간 변경) 에 따라 SceneNext 설정 
	void Update();						  // 
	void Render();						  // 콘솔창에 텍스트로 그리기 
	bool IsRunning() { return isRunning; };

}
