#include "Connection.h"
#include <cassert>
#include <iostream>

//public
SimpleSocket::SimpleSocket() {
	assert(WSAStartup(MAKEWORD(2, 2), &wsaData) == 0);
		std::cout << "Error!" << std::endl;
		

	hBSock = socket(PF_INET, SOCK_STREAM, 0);
	hRSock = 0;
	memset(&hBAddr, 0, sizeof(PSOCKADDR_IN));
	memset(&hRAddr, 0, sizeof(PSOCKADDR_IN));
	
	portnumb = 8008;		//default

	isServerSide = true;

}

inline void SimpleSocket::setPortNumb(int port) { //번호 범위 점검 해줘야하나?
	portnumb = port;	
}



//private 
void SimpleSocket::initSocket() {
	hBAddr.sin_family		= AF_INET;
	hBAddr.sin_addr.s_addr = htonl(INADDR_ANY);	//서버 ip = 현재 PC IP로 설정
	hBAddr.sin_port = htons(SimpleSocket::portnumb);
}

bool SimpleSocket::connection() {
	bind(hBSock, (SOCKADDR*)&hBAddr, sizeof(hBAddr));
		
		// 접속 받을수 있게
	listen(hBSock, 5);	// 접속대기 5
		

	// 연결 수락
	//szClntAddr = sizeof(clntAddr);
	//hRSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);	// 클라이언트와 통신 수립시 필요

	

	return true;

}