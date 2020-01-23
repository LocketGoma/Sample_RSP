#pragma once
#include "Resource.h"
#include "Games.h"
#include "Connection.h"
#include <string>
using namespace std;

class GameInterface {
	public:
		GameInterface();
		void Start();


	private:
		unique_ptr<Game_RSP> GameClinet;
		unique_ptr<SimpleSocket> GameNetwork;
		bool Selector();
		bool gamePackage();
		bool networkConnected; //����Ǿ����� ���� Ȯ��.
		string ResultMsg(int);	//���ڷ� ǥ���� ���и� ���ڿ��� ��ȯ.
		string RSPMsg(int);		//��¿� : ���������� �� ���� ���ڷ� ǥ��.

};