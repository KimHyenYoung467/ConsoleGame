#pragma once
#include "HeaderZiP.h"

System Setting;


struct MENU
{
	// ���� ǥ���� ���� �Ҵ� 
	int screenwidth_X = consoleRender::ScreenWidth();
	int screenheight_Y = consoleRender::ScreenHeight();

	// �� �ʱ�ȭ �Ǿ� �־�� ��. 
	char* map = new char[screenheight_Y * screenwidth_X + screenwidth_X];    // 2���� �迭

	void MenuInitialize();
	void MenuUpdate();
	void MenuRender();

	/**************************************************************/

	void MenuMAP();
};