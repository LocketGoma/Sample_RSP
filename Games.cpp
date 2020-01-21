#include "Games.h"


Game_RSP::Game_RSP() {
	win_count = 0;
	defeat_count = 0;
	isPlay = false;
	Reset_Seed();
}

//Public
int Game_RSP::GameAgent(int blue, int red) {	//이거 그냥 다 뜯어야하네;
	

	int gameResult = Result::draw;
	gameResult = GameMachine(blue, red);
	
	if (gameResult == Result::Win)
		win_count++;
	if (gameResult == Result::Lose)
		defeat_count++;	
	
	return gameResult;
}
int Game_RSP::Get_winpoint() const{
	return win_count;
}
int Game_RSP::Get_defeat() const {
	return defeat_count;
}
int Game_RSP::Input_data() {		//이게 호출이 제일 과할거 같은데...
	int input;
	std::cin >> input;	

	if (input > 3) {
		input %= 3;
		if (input == 0) {
			input = 3;
		}
	}
	return input;
}
int Game_RSP::RedSelect() {
	int input = com_rand();		//네트워크 연결시 상대방 결과, 비연결시 com 자동.


	return input;
}

//Private
int Game_RSP::GameMachine(int blue, int red) {
	//투입								결과
	//1:가위							-1	: 패배
	//2:바위							0	: 무승부
	//3:보								1	: 승리
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

