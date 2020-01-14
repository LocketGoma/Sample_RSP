#pragma once
#include "Resource.h"
using namespace RSPGames;

class Game_RSP {
	public :
		Game_RSP();
		int Get_result();
		int Get_defeat();
		int Input_data();		//가위바위보 선택
		bool GameAgent();		//메인 게임 에이전트,True : 결과 나옴 / False : 안나옴(Draw 등)
		

	private :
		int win_count;
		int defeat_count;

		void Reset_Seed();
		inline int com_rand();		//자동
		int GameMachine(int,int);	//핵심 머신

};