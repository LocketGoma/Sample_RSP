#pragma once
#include "Resource.h"
using namespace RSPGames;

class Game_RSP {
	public :
		Game_RSP();
		int Get_winpoint();
		int Get_defeat();
		int Input_data();		//���������� ����
		int GameAgent(int);		//-1 : �й� / 0 : ��� / 1 : �¸�
		
		//���� ���� ������Ʈ,True : ��� ���� / False : �ȳ���(Draw ��)

	private :
		int win_count;
		int defeat_count;
		bool isPlay;

		void Reset_Seed();
		inline int com_rand();		//�ڵ�
		int GameMachine(int,int);	//�ٽ� �ӽ�

};