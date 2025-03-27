#pragma once
#include "HeaderZiP.h"



struct System
{
	

	enum SceneType { MENU, PLAY, END }; // �� Ÿ�� 

	System::SceneType SceneCurrent;					// ���� �� 
	System::SceneType* NextScene = nullptr;			// ���� �� 

	void SceneInit();

	void ChangeScene(SceneType newScene);					     // ��Ȳ(�Է� �Ǵ� �ð� ����) �� ���� SceneNext ���� 
	void SceneUpdate();
	void SceneRender();											 // �ܼ�â�� �ؽ�Ʈ�� �׸��� 
	void ProcessInput();
	SceneType NextChangeIndex(SceneType scenecurrent);

	//bool IsRunning() { return isRunning; };					 // ������ ���� ������ �ƴ��� Ȯ���ϴ� ������ ��ȯ�Ѵ�.

	SceneType GetSceneType(SceneType scene) { return scene = SceneCurrent; }; // ���� ���� �����´�.
	SceneType SetSceneType(SceneType scene) { return scene = SceneCurrent; }; // ���� ���� �����Ѵ�. 


};


