#include "PLAY.h"




namespace PLAY
{

	void Initialize()
	{
	
		srand(time(NULL));
		COORD g_player = { 0,0 };
	}
	void RandomScore()
	{
		// 랜덤 함수를 받아서 , score 의 위치가 랜덤으로 나오게 한다. 

		int randomScore = rand() % MAP_X; 

		Render();

	}
	void Update()
	{
		KeyInput();

		if (g_Player.X < 0) g_Player.X = 0;

		if (g_Player.X >= ConsoleRenderer::ScreenWidth()) GManager::S_Player.X = ConsoleRenderer::ScreenWidth() - 1;
		
		if (g_Player.Y < 0) g_Player.Y = 0;
		if (g_Player.Y >= ConsoleRenderer::ScreenHeight())  GManager::S_Player.Y = ConsoleRenderer::ScreenHeight() - 1;
	}
					// 스코어를 랜덤으로 나타나게 한다. 
					// 스코어의 위치를 랜덤으로 나타나게 할 함수 
					// 스코어에 플레이어가 닿았을 때 점수를 증감 시키는 함수 

	char* Render()
	{
		ConsoleRenderer::ScreenClear();

		char buf[256] = { 0,};
		ConsoleRenderer::ScreenDrawString(0, 0, buf, FG_PINK_DARK);

		char temp = map[ConsoleRenderer::ScreenWidth() * ConsoleRenderer::ScreenHeight()];

		for (int i = 0; i < ConsoleRenderer::ScreenWidth(); ++i)
		{
			for (int j = 0; j < ConsoleRenderer::ScreenHeight(); ++j)
			{
				map[i * j]; 

				if (map[i * j] == 0)
				{
					printf(" "); 
				}
				ConsoleRenderer::ScreenDrawChar(0, 0, L'P', FG_WHITE);

				// 콘솔창에 띄울 Render 함수 맵을 콘솔창에 띄운다. 
				ConsoleRenderer::ScreenFlipping();
			}
		}
		
	}
}


void Move(short* X, short* Y, int x, int y)
{
	char PMove = PLAY::map[*X + x* *Y + y];

	if (PLAY::map[*X +  *Y ] == 0)
	{
		printf(" "); // 지우기 
	}
	else if (PLAY::map[*X + *Y] == '_')
	{

	}

	*X = x; 
	*Y = y;

}
void KeyInput()
{
	if (Input::IsKeyDown(VK_LEFT)) { //왼쪽
		g_Player.X--;
	}
	if (Input::IsKeyDown(VK_RIGHT)) { //오른쪽
		g_Player.X++;
	}
	if (Input::IsKeyDown(VK_UP)) { //위
		g_Player.Y--;
	}
	if (Input::IsKeyDown(VK_DOWN)) { //아래
		g_Player.Y++;
	}
	if (Input::IsKeyDown(VK_ESCAPE)) { //종료
		g_bQuit = true;
	}

}