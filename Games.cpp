#include "Games.h"


Game_RSP::Game_RSP() {
	win_count = 0;
	defeat_count = 0;
	Reset_Seed();
}

//Public
bool Game_RSP::GameAgent() {
	int blue = Input_data();
	int red = com_rand();		//��Ʈ��ũ ����� ���� ���, �񿬰�� com �ڵ�.
	bool GameResult;

	if (blue == 0)
		return false;//����
	else if (blue == -1)
		return true;//�ڷΰ���
	


	if (GameMachine(blue, red) == Result::draw) {
		return false;
	}
	else
		return true;
	
	


}
int Game_RSP::Get_result() {
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

