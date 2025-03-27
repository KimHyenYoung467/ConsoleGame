#include "PLAY.h"




	void Play::Initialize()
	{
		consoleRender::ScreenInit();

		// 랜덤화 시드
		srand(time(NULL));

		// 맵 초기화
		map[screenheight_Y * screenwidth_X + screenwidth_X] = 0, 1; 
		map[SC.score_height * screenwidth_X + SC.score_width] = 0; // 스코어 위치 좌표 맵 초기화 

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

		// 맵을 그린다.
		Map();
		consoleRender::ScreenDrawString(0, 0, map, FG_PINK_DARK);				// 맵 속성 변경 (위치, 색) 
		printf_s(buf, "스코어 점수 : %d", SC.score);


		
		// 콘솔창에 띄울 Render 함수 맵을 콘솔창에 띄운다. 
		consoleRender::ScreenFlipping();
		
		delete[] map; 
	}



	/********************************************************************************************************/

												// 랜덤 스코어 아이템 메소드 

	/********************************************************************************************************/

	void Play::RandomScore()
	{
		// 랜덤 함수를 받아서 , score 의 위치가 랜덤으로 나오게 한다. 

		int randomScore = rand() % (screenwidth_X * screenheight_Y);

		// 스코어의 위치를 랜덤으로 나타나게 한다.
		map[SC.score_height * screenwidth_X + SC.score_width];

		for (int i = 0; i < screenwidth_X; ++i)
		{
			for (int j = 0; j < screenheight_Y; ++j)
			{
				if (map[i * screenwidth_X + j] == 3) // 스코어 아이템이 있을 때, 
				{
					// 랜덤하게 스코어 위치를 지정 
					i = SC.score_width * randomScore;
					j = SC.score_height * randomScore + i;
				}
				// 랜덤하게 지정한 스코어 위치를 'S'로 표시 
				map[i * screenwidth_X + j] = 'S';
			}
		}
	}

	void Play::ScorePlusMinus() // 스코어에 플레이어가 닿았을 때 점수를 증감 시키는 함수
	{
		// 시간을 받아서 일정 시간이 지나면 스코어가 사라지게 한다.
		// 화면 시간 
		float time = Time::GetDeltaTime();
		
		// 스코어 위치에 플레이어의 위치가 동일한 지 체크 하기 
		if (g_Player.X == 'S' && g_Player.Y == 'S')
		{
			isTouch = true; 
			SC.score++; // 스코어 증가 
		}

		// 5초가 지나면 스코어 아이템이 사라지게 한다.
		if (time <= 5 && isTouch == false)
		{
			// 스코어 아이템 표현 지우기 
			if (map[SC.score_height * screenwidth_X + SC.score_width] == 'S')
			{
				map[SC.score_height * screenwidth_X + SC.score_width] = '_';
				return; 
			}
			
		}
	}

	void Play::Map()
	{

		// 맵을 그린다.
		
		for (int i = 0; i < screenwidth_X; ++i)
		{
			for (int j = 0; j < screenheight_Y; ++j)
			{
				map[j * screenwidth_X + (screenwidth_X - 1)] = 4;
				map[j * screenwidth_X + (SC.score_width - 2)] = 3; // 스코어 위치 

				if (map[i * screenwidth_X + j] == 0)
				{
					printf(" ");										// 빈공간 출력 
				}
				else if (map[i * screenwidth_X + j] == 4)
				{
				

				}
				else if (map[i * screenwidth_X + j] == 3)
				{
					RandomScore(); 									    // 스코어를 랜덤으로 나타나게 한다.
				
					printf("S");										// 스코어 아이템 출력  
				}
				if (j == screenheight_Y - 1)
				{
					printf("_");										// 바닥 
				}
			}
		}
	}
	void Play::MoveCheck(short* X, short* Y, int x, int y) // 플레이어의 움직임을 받아서 처리한다. 
	{

		if (*X == 0 && *Y == (PL.screenheight_Y - 1)) // 플레이어의 위치가 0 -1 에 위치했을 때 
		{
			*X = 0;
			*Y = 0;

			printf(" "); // 지우기 
		}

		// 플레이어의 위치를 받아서 입력에 따라서 받을 수 있도록
		*X = x;
		*Y = y;

		if (*X == g_Player.X && *Y == g_Player.Y)
		{
			// 플레이어가 벽에 부딪혔을 때 
			isCrash = true;
			// x, y 값을 받아서 입력에 따라서 받을 수 있도록 
			consoleRender::ScreenDrawChar(*X--, *Y--, L'P', FG_WHITE);
		}
		if (*X == SC.score_width && *Y == SC.score_height)
		{
			// 플레이어가 스코어 아이템에 닿았을 때 
			ScorePlusMinus();
			// x, y 값을 받아서 입력에 따라서 받을 수 있도록 
			consoleRender::ScreenDrawChar(*X, *Y, L'S', FG_WHITE);
		}
	}
