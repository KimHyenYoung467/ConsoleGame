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

	// ���� �÷��� ���� ��, �ʱ�ȭ �Ǿ� �־�� ��. 
	char* map = new char[screenheight_Y * screenwidth_X + screenwidth_X];    // 2���� �迭

	void Initialize();											// Scene ó�� ������ �� ���� �� �Լ� 
	bool isTouch = false;

	void Update();												// Play �� ��� ������Ʈ �Ǿ�� �� �͵� 
	void Render();

	// Play �� ��� ������ �Ǿ�� �� �͵�
	void RandomScore();											// ���ھ �������� ��Ÿ���� �Ѵ�.
	void Map();													// ���� �׸��� �Լ�
	void MoveCheck(short* X, short* Y, int x, int y);			// �÷��̾��� �������� �޾Ƽ� ó���ϴ� �Լ� 
	void ScorePlusMinus();

	bool isPlaying = false;										// ������ ���� ������ �ƴ��� Ȯ���ϴ� ���� 
	bool isCrash = false; 										// �÷��̾ ���� �ε������� Ȯ���ϴ� ����						// �÷��̾ ���� �ε������� Ȯ���ϴ� ���� 
} play;
