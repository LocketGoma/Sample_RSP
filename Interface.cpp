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
		cout << "���� ���࿡ ������ ������ϴ�. �ٽ� �������ּ���." << endl;
		cout << "������ �����մϴ�." << endl;

		getchar();

		exit(0);
	}

	//��Ʈ��ũ ����κ�



	while (true) {
		if (Selector() == false)
			break;
	}
}

bool GameInterface::Selector() {

	cout << "�޴��� �������ּ���." << endl;
	cout << "1. ���������� ���� / 2. ��Ʈ��ũ ���� / 3. ��� Ȯ�� / 0. ���� ����\n\n" << endl;


	int selectCode;
	cin >> selectCode;
	
	switch (selectCode) {
	case 1: {
		GameClinet->GameAgent();


		break;
		}
	case 2: {
		cout << "�������� ����Դϴ�." << endl;
		break;	
	}
	case 3: {
		cout << "============���============" << endl;
		cout << "�¸� : " << GameClinet->Get_winpoint() << "    ";
		cout << "�й� : " << GameClinet->Get_defeat() << endl;
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