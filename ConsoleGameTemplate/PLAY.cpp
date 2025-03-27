#include "PLAY.h"




	void Play::Initialize()
	{
		consoleRender::ScreenInit();

		// ����ȭ �õ�
		srand(time(NULL));

		// �� �ʱ�ȭ
		map[screenheight_Y * screenwidth_X + screenwidth_X] = 0, 1; 
		map[SC.score_height * screenwidth_X + SC.score_width] = 0; // ���ھ� ��ġ ��ǥ �� �ʱ�ȭ 

	}

	void Play::Update()
	{
		MoveCheck(&g_Player.X, &g_Player.Y, 0, 0);

		Setting.ProcessInput();

	}

	void Play::Render()
	{
		consoleRender::ScreenClear();
		
		char buf[256] = { 0, };
		consoleRender::ScreenDrawString(0, 0, buf, FG_BLUE);

		// ���� �׸���.
		Map();
		consoleRender::ScreenDrawString(0, 0, map, FG_PINK_DARK);				// �� �Ӽ� ���� (��ġ, ��) 
		printf_s(buf, "���ھ� ���� : %d", SC.score);


		
		// �ܼ�â�� ��� Render �Լ� ���� �ܼ�â�� ����. 
		consoleRender::ScreenFlipping();
		
		delete[] map; 
	}



	/********************************************************************************************************/

												// ���� ���ھ� ������ �޼ҵ� 

	/********************************************************************************************************/

	void Play::RandomScore()
	{
		// ���� �Լ��� �޾Ƽ� , score �� ��ġ�� �������� ������ �Ѵ�. 

		int randomScore = rand() % (screenwidth_X * screenheight_Y);

		// ���ھ��� ��ġ�� �������� ��Ÿ���� �Ѵ�.
		map[SC.score_height * screenwidth_X + SC.score_width];

		for (int i = 0; i < screenwidth_X; ++i)
		{
			for (int j = 0; j < screenheight_Y; ++j)
			{
				if (map[i * screenwidth_X + j] == 3) // ���ھ� �������� ���� ��, 
				{
					// �����ϰ� ���ھ� ��ġ�� ���� 
					i = SC.score_width * randomScore;
					j = SC.score_height * randomScore + i;
				}
				// �����ϰ� ������ ���ھ� ��ġ�� 'S'�� ǥ�� 
				map[i * screenwidth_X + j] = 'S';
			}
		}
	}

	void Play::ScorePlusMinus() // ���ھ �÷��̾ ����� �� ������ ���� ��Ű�� �Լ�
	{
		// �ð��� �޾Ƽ� ���� �ð��� ������ ���ھ ������� �Ѵ�.
		// ȭ�� �ð� 
		float time = Time::GetDeltaTime();
		
		// ���ھ� ��ġ�� �÷��̾��� ��ġ�� ������ �� üũ �ϱ� 
		if (g_Player.X == 'S' && g_Player.Y == 'S')
		{
			isTouch = true; 
			SC.score++; // ���ھ� ���� 
		}

		// 5�ʰ� ������ ���ھ� �������� ������� �Ѵ�.
		if (time <= 5 && isTouch == false)
		{
			// ���ھ� ������ ǥ�� ����� 
			if (map[SC.score_height * screenwidth_X + SC.score_width] == 'S')
			{
				map[SC.score_height * screenwidth_X + SC.score_width] = '_';
				return; 
			}
			
		}
	}

	void Play::Map()
	{

		// ���� �׸���.
		
		for (int i = 0; i < screenwidth_X; ++i)
		{
			for (int j = 0; j < screenheight_Y; ++j)
			{
				map[j * screenwidth_X + (screenwidth_X - 1)] = 4;
				map[j * screenwidth_X + (SC.score_width - 2)] = 3; // ���ھ� ��ġ 

				if (map[i * screenwidth_X + j] == 0)
				{
					printf(" ");										// ����� ��� 
				}
				else if (map[i * screenwidth_X + j] == 4)
				{
				

				}
				else if (map[i * screenwidth_X + j] == 3)
				{
					RandomScore(); 									    // ���ھ �������� ��Ÿ���� �Ѵ�.
				
					printf("S");										// ���ھ� ������ ���  
				}
				if (j == screenheight_Y - 1)
				{
					printf("_");										// �ٴ� 
				}
			}
		}
	}
	void Play::MoveCheck(short* X, short* Y, int x, int y) // �÷��̾��� �������� �޾Ƽ� ó���Ѵ�. 
	{

		if (*X == 0 && *Y == (PL.screenheight_Y - 1)) // �÷��̾��� ��ġ�� 0 -1 �� ��ġ���� �� 
		{
			*X = 0;
			*Y = 0;

			printf(" "); // ����� 
		}

		// �÷��̾��� ��ġ�� �޾Ƽ� �Է¿� ���� ���� �� �ֵ���
		*X = x;
		*Y = y;

		if (*X == g_Player.X && *Y == g_Player.Y)
		{
			// �÷��̾ ���� �ε����� �� 
			isCrash = true;
			// x, y ���� �޾Ƽ� �Է¿� ���� ���� �� �ֵ��� 
			consoleRender::ScreenDrawChar(*X--, *Y--, L'P', FG_WHITE);
		}
		if (*X == SC.score_width && *Y == SC.score_height)
		{
			// �÷��̾ ���ھ� �����ۿ� ����� �� 
			ScorePlusMinus();
			// x, y ���� �޾Ƽ� �Է¿� ���� ���� �� �ֵ��� 
			consoleRender::ScreenDrawChar(*X, *Y, L'S', FG_WHITE);
		}
	}
