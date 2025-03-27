#pragma once
#include "HeaderZiP.h"



struct System
{
	

	enum SceneType { MENU, PLAY, END }; // 씬 타입 

	System::SceneType SceneCurrent;					// 현재 씬 
	System::SceneType* NextScene = nullptr;			// 다음 씬 

	void SceneInit();

	void ChangeScene(SceneType newScene);					     // 상황(입력 또는 시간 변경) 에 따라 SceneNext 설정 
	void SceneUpdate();
	void SceneRender();											 // 콘솔창에 텍스트로 그리기 
	void ProcessInput();
	SceneType NextChangeIndex(SceneType scenecurrent);

	//bool IsRunning() { return isRunning; };					 // 게임이 진행 중인지 아닌지 확인하는 변수를 반환한다.

	SceneType GetSceneType(SceneType scene) { return scene = SceneCurrent; }; // 현재 씬을 가져온다.
	SceneType SetSceneType(SceneType scene) { return scene = SceneCurrent; }; // 현재 씬을 지정한다. 


};


