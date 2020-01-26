#pragma once
#pragma comment(lib, "ws2_32.lib")
#include "Resource.h"
#include <sys/types.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <string.h>


//https://nroses-taek.tistory.com/105
//https://stackoverflow.com/questions/35019684/socket-programming-simple-chat-c
//https://m.blog.naver.com/tmone1/10181445622

//실제 "환경 대응"식 작업시에는, unix 기반에서는 sys/socket.h, windows 기반에서는 winsock를 사용하면 된다.
// = 두 환경을 비교, 대응할 수 있는 방식으로 작성해야 할 것

//그러니까... 서버사이드 하나 만들고 클라이언트 사이드 만들어서 쓰면 되겠네

class SimpleSocket {
	public:
		//SOCKET = uint
		SOCKET hBSock;		//'Server' 포지션
		SOCKET hRSock;		//'Client' 포지션
		SOCKADDR_IN hBAddr; //'Server' 포지션
		SOCKADDR_IN hRAddr; //'Client' 포지션

		SOCKET cSock;		//접속용 클라이언트 소캣
		SOCKADDR_IN cAddr;	//접속용 클라이언트 주소

		int portnumb;		//기본 포트번호

		SimpleSocket();

		
		inline void setPortNumb(int port);		//포트번호 설정
		bool makeServer();		//연결 대기 (서버화)
		bool JoinServer();		//연결 수립용

	private:
		WSADATA wsaData;
		bool isServerSide;		//서버파트 (=접속대기)인지, 클라파트(=접속요청)인지.
		int szRAddr;			//모임? 대체모임?
		std::string ServerIP;



		//Server Side
		void initSocket();		//초기정보 가공.. 성공시 체크하고싶은데.
		bool SocKBind();		//통신 연결
		bool SendingMessage();
		bool CloseSocket();
		

		//Client Side
		void initConnect();
		bool ClientBind();		//통신 연결
		bool CallingMessange();
		char* setOppositIP();



};

/*
struct sockaddr_in {
		short   sin_family;
		u_short sin_port;
		struct  in_addr sin_addr;
		char    sin_zero[8];
};

*/

//if (A(val)) { if (B(val)) { return(C(val)); } }
//return(false);
//= 3개 다 성공해야 실행됨.