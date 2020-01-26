#include "Interface.h"


int main() {
	//GameInterface* Game = new GameInterface();
	unique_ptr<GameInterface> Game = make_unique<GameInterface>();
	Game->Start();

	return 0;
}







GameInterface::GameInterface() {
	GameClinet = make_unique<Game_RSP>();
	//GameNetwork = make_unique<SimpleSocket>();
	networkConnected = false;
}

void GameInterface::Start() {
	if (GameClinet == nullptr) {
		cout << "���� ���࿡ ������ ������ϴ�. �ٽ� �������ּ���." << endl;
		cout << "������ �����մϴ�." << endl;

		cout << getchar();

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
		cout << "1 : ���� / 2 : ���� / 3 : �� " << endl;
		cout << "-1 : �޴��� ���ư��� / 0 : �� ����" << endl;
		this->gamePackage();

		break;
		}
	case 2: {
		cout << "�������� ����Դϴ�." << endl;
		break;	
	}
	case 3: {
		cout << "===============���===============" << endl;
		cout << "�¸� : " << GameClinet->Get_winpoint() << "    ";
		cout << "�й� : " << GameClinet->Get_defeat()<< "    ";
		cout << "�·� : ";
		cout.width(3);
		if (GameClinet->Get_defeat() != 0)
			cout << static_cast<float>(GameClinet->Get_winpoint()) / static_cast<float>(GameClinet->Get_winpoint() + GameClinet->Get_defeat()) * 100 ;
		else
			GameClinet->Get_winpoint() !=0 ? cout<<"100" :cout << "0";		//Div zero.
		cout << "%" << endl;

		cout << "==================================" << endl;
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

	cout << getchar();

	return true;
}

bool GameInterface::gamePackage() {
	int blueInput=0;
	int redInput = 0;
	int GameResult = RSPGames::Result::draw;


	blueInput = GameClinet->Input_data();

	if (blueInput == RSPGames::Option::Avoid) {
		cout << "����ȭ������ ���ư��ϴ�." << endl;

		return false;
	}
	else if (blueInput == RSPGames::Option::Surrender) {
		cout << "�̹� ���� �����մϴ�. ������ �й�� ��ϵ˴ϴ�." << endl;
	}
	else {
		cout << "�� : ";
		cout << RSPMsg(blueInput) << endl;
		
		redInput = GameClinet->RedSelect();
		cout << "��� : ";
		cout << RSPMsg(redInput) << endl;

		GameResult = GameClinet->GameAgent(blueInput, redInput);

		cout << "���ӿ��� ";
		if (GameResult == RSPGames::Result::draw)
			cout << "�����ϴ�.";
		else {
			cout << ResultMsg(GameResult);
			cout << "�ϼ̽��ϴ�.";
		}
		cout << endl;

	}


	return true;

}

string GameInterface::ResultMsg(int msg) {
	string result;
	if (msg == RSPGames::Result::Lose)
		result = "�й�";
	if (msg == RSPGames::Result::draw)
		result = "���";
	if (msg == RSPGames::Result::Win)
		result = "�¸�";

	return result;
}
string GameInterface::RSPMsg(int msg) {
	string result;
	if (msg == RSPGames::Card::Sessios)
		result = "����";
	if (msg == RSPGames::Card::Rock)
		result = "����";
	if (msg == RSPGames::Card::Paper)
		result = "��";

	return result;
}