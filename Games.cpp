#include "Games.h"


Game_RSP::Game_RSP() {
	win_count = 0;
	defeat_count = 0;
	isPlay = false;
	Reset_Seed();
}

//Public
bool Game_RSP::GameAgent() {	//�̰� �׳� �� �����ϳ�;
	int blue = Input_data();
	int red = com_rand();		//��Ʈ��ũ ����� ���� ���, �񿬰�� com �ڵ�.
	

	if (blue == 0) 
		return false;//����	
	else if (blue == -1) {
		isPlay = false;
		return true;//�ڷΰ���
	}	

	int gameResult = Result::draw;
	gameResult = GameMachine(blue, red);
	if (gameResult == Result::draw) {
		return false;
	}
	else {
		if (gameResult == Result::Win)
			win_count++;
		if (gameResult == Result::Lose)
			defeat_count++;

		return true;
	}
}
int Game_RSP::Get_winpoint() {
	return win_count;
}
int Game_RSP::Get_defeat() {
	return defeat_count;
}
int Game_RSP::Input_data() {		//�̰� ȣ���� ���� ���Ұ� ������...
	int input;
	std::cin >> input;	

	return input;
}

//Private
int Game_RSP::GameMachine(int blue, int red) {
	//����								���
	//1:����							-1	: �й�
	//2:����							0	: ���º�
	//3:��								1	: �¸�
	int answer = 0;
	if (blue == red)
		return Result::draw;


	if (blue == Card::Rock) {
		if (red == Card::Sessios) {
			answer = Result::Win;
		}
		else if (red == Card::Paper) {
			answer = Result::Lose;
		}
	}
	else if (blue == Card::Sessios) {
		if (red == Card::Paper) {
			answer = Result::Win;
		}
		else if (red == Card::Rock) {
			answer = Result::Lose;
		}
	}
	else if (blue == Card::Paper) {
		if (red == Card::Rock) {
			answer = Result::Win;
		}
		else if (red == Card::Sessios) {
			answer = Result::Lose;
		}
	}
	
	return answer;
}


void Game_RSP::Reset_Seed() {
	srand((unsigned int)time(NULL));
}

inline int Game_RSP::com_rand() {	
	return (rand() % 3)+1;
}

