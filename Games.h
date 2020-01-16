#pragma once
#include "Resource.h"
using namespace RSPGames;

class Game_RSP {
	public :
		Game_RSP();
		int Get_winpoint();
		int Get_defeat();
		int Input_data();		//가위바위보 선택
		int GameAgent(int);		//-1 : 패배 / 0 : 비김 / 1 : 승리
		
		//메인 게임 에이전트,True : 결과 나옴 / False : 안나옴(Draw 등)

	private :
		int win_count;
		int defeat_count;
		bool isPlay;

		void Reset_Seed();
		inline int com_rand();		//자동
		int GameMachine(int,int);	//핵심 머신

};