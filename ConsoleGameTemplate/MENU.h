#pragma once
#include "HeaderZiP.h"

System Setting;


struct MENU
{
	// 맵을 표시할 동적 할당 
	int screenwidth_X = consoleRender::ScreenWidth();
	int screenheight_Y = consoleRender::ScreenHeight();

	// 맵 초기화 되어 있어야 함. 
	char* map = new char[screenheight_Y * screenwidth_X + screenwidth_X];    // 2차원 배열

	void MenuInitialize();
	void MenuUpdate();
	void MenuRender();

	/**************************************************************/

	void MenuMAP();
};