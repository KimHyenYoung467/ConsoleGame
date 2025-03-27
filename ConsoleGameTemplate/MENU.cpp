#include "MENU.h"
#include "ConsoleGameTemplate.cpp"




	// 노가다 형식 맵 그리기 

	void MENU::MenuInitialize() // 초기화 함수 
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

		// 맵을 그린다.
		MenuMAP();
		consoleRender::ScreenDrawString(MENU::screenwidth_X / 2, MENU::screenheight_Y - 1, "아무 키나 눌러주세요.", FG_BLUE);
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
		// 메뉴 스크린에 띄울 맵 그리기 
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
	
