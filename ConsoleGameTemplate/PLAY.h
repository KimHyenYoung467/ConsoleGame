#pragma once
#include "HeaderZiP.h"


struct Play
{
	
	struct score
	{
		int score;
		int score_width;
		int score_height;

	} SC;
	int screenwidth_X = consoleRender::ScreenWidth();
	int screenheight_Y = consoleRender::ScreenHeight();

	// 게임 플레이 진행 시, 초기화 되어 있어야 함. 
	char* map = new char[screenheight_Y * screenwidth_X + screenwidth_X];    // 2차원 배열

	void Initialize();											// Scene 처음 진입할 때 시작 할 함수 
	bool isTouch = false;

	void Update();												// Play 중 계속 업데이트 되어야 할 것들 
	void Render();

	// Play 중 계속 렌더링 되어야 할 것들
	void RandomScore();											// 스코어를 랜덤으로 나타나게 한다.
	void Map();													// 맵을 그리는 함수
	void MoveCheck(short* X, short* Y, int x, int y);			// 플레이어의 움직임을 받아서 처리하는 함수 
	void ScorePlusMinus();

	bool isPlaying = false;										// 게임이 진행 중인지 아닌지 확인하는 변수 
	bool isCrash = false; 										// 플레이어가 벽에 부딪혔는지 확인하는 변수						// 플레이어가 벽에 부딪혔는지 확인하는 변수 
} play;
