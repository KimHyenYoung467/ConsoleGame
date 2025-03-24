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
		// ���� �Լ��� �޾Ƽ� , score �� ��ġ�� �������� ������ �Ѵ�. 

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
					// ���ھ �������� ��Ÿ���� �Ѵ�. 
					// ���ھ��� ��ġ�� �������� ��Ÿ���� �� �Լ� 
					// ���ھ �÷��̾ ����� �� ������ ���� ��Ű�� �Լ� 

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

				// �ܼ�â�� ��� Render �Լ� ���� �ܼ�â�� ����. 
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
		printf(" "); // ����� 
	}
	else if (PLAY::map[*X + *Y] == '_')
	{

	}

	*X = x; 
	*Y = y;

}
void KeyInput()
{
	if (Input::IsKeyDown(VK_LEFT)) { //����
		g_Player.X--;
	}
	if (Input::IsKeyDown(VK_RIGHT)) { //������
		g_Player.X++;
	}
	if (Input::IsKeyDown(VK_UP)) { //��
		g_Player.Y--;
	}
	if (Input::IsKeyDown(VK_DOWN)) { //�Ʒ�
		g_Player.Y++;
	}
	if (Input::IsKeyDown(VK_ESCAPE)) { //����
		g_bQuit = true;
	}

}