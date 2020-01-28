#pragma once
#include "Resource.h"
#include "Games.h"
#include "Connection.h"
#include <string>

//#define SockTEST

using namespace std;

class GameInterface {
	public:
		GameInterface();
		void Start();


	private:
		unique_ptr<Game_RSP> GameClinet;
		bool Selector();
		bool gamePackage();		
		string ResultMsg(int);	//���ڷ� ǥ���� ���и� ���ڿ��� ��ȯ.
		string RSPMsg(int);		//��¿� : ���������� �� ���� ���ڷ� ǥ��.


		unique_ptr<SimpleSocket> GameNServer;
		unique_ptr<SimpleConnect> GameNClient;
		bool networkConnected; //����Ǿ����� ���� Ȯ��.
		bool setServer();		//���� ��� (=�� ����)
		bool setClient();		//���� �õ� (=�� ����)

#ifdef SockTEST
		bool Selector(bool swit);	//�ӽÿ�
#endif

};