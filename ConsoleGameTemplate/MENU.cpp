#include "MENU.h"
#include "ConsoleGameTemplate.cpp"




	// �밡�� ���� �� �׸��� 

	void MENU::MenuInitialize() // �ʱ�ȭ �Լ� 
	{
		consoleRender::ScreenInit();

		map[screenheight_Y * screenwidth_X + screenwidth_X] = 0;
															

	}

	void MENU::MenuUpdate()
	{

	}

	void MENU::MenuRender()
	{
		consoleRender::ScreenClear(); 

		char buf[256] = { 0, };
		consoleRender::ScreenDrawString(0, 0, buf, FG_BLUE);

		// ���� �׸���.
		MenuMAP();
		consoleRender::ScreenDrawString(MENU::screenwidth_X / 2, MENU::screenheight_Y - 1, "�ƹ� Ű�� �����ּ���.", FG_BLUE);
		getchar();

		Setting.ProcessInput(); 
		Setting.NextChangeIndex(Setting.SceneCurrent);		
		
		consoleRender::ScreenFlipping();

		

		delete[] map; 
	}

	/********************************************************************************************************/

												// Menu Map 

	/********************************************************************************************************/

	void MENU::MenuMAP()
	{
		// �޴� ��ũ���� ��� �� �׸��� 
		printf("					/////////////       /////////////"); 
		printf("					//           //     //			  //"); 
		printf("					//           //     //			   //"); 
		printf("					//           //     //			   //"); 
		printf("					/////////////////////////////////////");
		printf("					//           //	    //			   //");
		printf("					//           //	    //			  //");
		printf("					//           //	    //			 //");
		printf("					//           //	     ////////////");

	}
	
