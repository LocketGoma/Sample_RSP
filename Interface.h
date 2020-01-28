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
		string ResultMsg(int);	//숫자로 표현된 승패를 문자열로 변환.
		string RSPMsg(int);		//출력용 : 가위바위보 낸 것을 문자로 표현.


		unique_ptr<SimpleSocket> GameNServer;
		unique_ptr<SimpleConnect> GameNClient;
		bool networkConnected; //연결되었는지 여부 확인.
		bool setServer();		//접속 대기 (=방 열기)
		bool setClient();		//접속 시도 (=방 참여)

#ifdef SockTEST
		bool Selector(bool swit);	//임시용
#endif

};