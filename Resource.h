#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>



// 1 - ���� / 2 - ���� / 3- - ��
// 0 - ������ �й�
// -1 - �ڷΰ���
// �� �� : n%3

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