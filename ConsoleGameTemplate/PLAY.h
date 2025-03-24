#pragma once
#include "ConsoleRenderer.h"
#include <stdio.h>
#include "Input.h"
#include "System.h"
#include "ConsoleGameTemplate.cpp"

#define MAP_X 10 
#define MAP_Y 10 
namespace PLAY
{
	// ���� �÷��� ���� ��, 1�� ��ġ�� �ʱ�ȭ �Ǿ� �־�� ��. 
	char* map = new char(ConsoleRenderer::ScreenWidth() 
							* ConsoleRenderer::ScreenHeight());
	
	
	/*char MAP[MAP_X][MAP_Y] = {  0,0,0,0,0,0,0,
								  0,0,0,0,0,0,0,
								  0,0,0,0,0,3,0,
								  0,1,0,0,0,0,0,
								  2,2,2,2,2,2,2, };
								  */

	void Initialize(); // Scene ó�� ������ �� ���� �� �Լ� 
	void RandomScore(); 
	void Update();    // Play �� ��� ������Ʈ �Ǿ�� �� �͵� 
	char* Render();
	
}
