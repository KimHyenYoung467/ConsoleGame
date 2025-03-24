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
	// 게임 플레이 진행 시, 1의 위치가 초기화 되어 있어야 함. 
	char* map = new char(ConsoleRenderer::ScreenWidth() 
							* ConsoleRenderer::ScreenHeight());
	
	
	/*char MAP[MAP_X][MAP_Y] = {  0,0,0,0,0,0,0,
								  0,0,0,0,0,0,0,
								  0,0,0,0,0,3,0,
								  0,1,0,0,0,0,0,
								  2,2,2,2,2,2,2, };
								  */

	void Initialize(); // Scene 처음 진입할 때 시작 할 함수 
	void RandomScore(); 
	void Update();    // Play 중 계속 업데이트 되어야 할 것들 
	char* Render();
	
}
