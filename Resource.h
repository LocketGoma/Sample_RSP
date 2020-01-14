#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>



// 1 - 가위 / 2 - 바위 / 3- - 보
// 0 - 무조건 패배
// -1 - 뒤로가기
// 그 외 : n%3

namespace RSPGames {
	typedef enum Card :int {
		Rock = 1,
		Sessios = 2,
		Paper = 3
	}Card;

	typedef enum Result :int {
		Win = 1,
		Lose = -1,
		draw = 0
	}Result;
}