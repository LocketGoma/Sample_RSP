#include "Interface.h"


int main() {
	GameInterface* Game = new GameInterface();
	Game->Start();

	return 0;
}







GameInterface::GameInterface() {
	GameClinet = new Game_RSP();
	networkConnected = false;
}

void GameInterface::Start() {
	if (GameClinet == nullptr) {
		cout << "게임 실행에 문제가 생겼습니다. 다시 실행해주세요." << endl;
		cout << "게임을 종료합니다." << endl;

		getchar();

		exit(0);
	}

	//네트워크 연결부분



	while (true) {
		if (Selector() == false)
			break;
	}
}

bool GameInterface::Selector() {

	cout << "메뉴를 선택해주세요." << endl;
	cout << "1. 가위바위보 실행 / 2. 네트워크 연결 / 3. 결과 확인 / 0. 게임 종료\n\n" << endl;


	int selectCode;
	cin >> selectCode;
	
	switch (selectCode) {
	case 1: {
		cout << "1 : 가위 / 2 : 바위 / 3 : 보 " << endl;
		cout << "-1 : 메뉴로 돌아가기 / 0 : 턴 포기" << endl;
		this->gamePackage();

		break;
		}
	case 2: {
		cout << "개발중인 기능입니다." << endl;
		break;	
	}
	case 3: {
		cout << "============결과============" << endl;
		cout << "승리 : " << GameClinet->Get_winpoint() << "    ";
		cout << "패배 : " << GameClinet->Get_defeat() << endl;
		cout << "============================" << endl;
		break;
	}
	case 0: {

		return false;
		break;
	}
	default: {
		;
		break;
	}
		   
		   
	}

	getchar();

	return true;
}

bool GameInterface::gamePackage() {
	int blueInput=0;
	int redInput = 0;
	int GameResult = RSPGames::Result::draw;


	blueInput = GameClinet->Input_data();

	if (blueInput == RSPGames::Option::Avoid) {
		cout << "메인화면으로 돌아갑니다." << endl;

		return false;
	}
	else if (blueInput == RSPGames::Option::Surrender) {
		cout << "이번 턴을 포기합니다. 무조건 패배로 기록됩니다." << endl;
	}
	else {
		cout << "나 : ";
		cout << RSPMsg(blueInput) << endl;
		
		redInput = GameClinet->RedSelect();
		cout << "상대 : ";
		cout << RSPMsg(redInput) << endl;

		GameResult = GameClinet->GameAgent(blueInput, redInput);

		cout << "게임에서 ";
		if (GameResult == RSPGames::Result::draw)
			cout << "비겼습니다.";
		else {
			cout << ResultMsg(GameResult);
			cout << "하셨습니다.";
		}
		cout << endl;

	}


	return true;

}

string GameInterface::ResultMsg(int msg) {
	string result;
	if (msg == RSPGames::Result::Lose)
		result = "패배";
	if (msg == RSPGames::Result::draw)
		result = "비김";
	if (msg == RSPGames::Result::Win)
		result = "승리";

	return result;
}
string GameInterface::RSPMsg(int msg) {
	string result;
	if (msg == RSPGames::Card::Sessios)
		result = "가위";
	if (msg == RSPGames::Card::Rock)
		result = "바위";
	if (msg == RSPGames::Card::Paper)
		result = "보";

	return result;
}