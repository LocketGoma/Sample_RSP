#pragma once
#include "Resource.h"
#include <sys/types.h>
#include <winsock.h>


//https://stackoverflow.com/questions/35019684/socket-programming-simple-chat-c
//https://m.blog.naver.com/tmone1/10181445622

//실제 "환경 대응"식 작업시에는, unix 기반에서는 sys/socket.h, windows 기반에서는 winsock를 사용하면 된다.
// = 두 환경을 비교, 대응할 수 있는 방식으로 작성해야 할 것


class SimpleSocket {
	public:
		//SOCKET = uint
		SOCKET hBSock;		//'Server' 포지션
		SOCKET hRSock;		//'Client' 포지션
		SOCKADDR_IN hBAddr; //'Server' 포지션
		SOCKADDR_IN hRAddr; //'Client' 포지션

		int portnumb;		//기본 포트번호

		SimpleSocket();

		bool setOppositIP();
		bool setPortNumb();

	private:
		WSADATA wsaData;


		bool initSocket();		//초기정보 가공


};

/*
struct sockaddr_in {
		short   sin_family;
		u_short sin_port;
		struct  in_addr sin_addr;
		char    sin_zero[8];
};

*/