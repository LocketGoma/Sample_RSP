#include "Interface.h"


int main() {
	GameInterface* Game = new GameInterface();
	Game->Start();

	return 0;
}







GameInterface::GameInterface() {
	GameClinet = new Game_RSP();
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
		GameClinet->GameAgent();


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

	return true;
}