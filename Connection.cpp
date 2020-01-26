#include "Connection.h"
#include <cassert>
#include <iostream>

//public
SimpleSocket::SimpleSocket() {
	assert(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0);
		std::cout << "Error!" << std::endl;
		
	//SeverSide Clear
	hBSock = socket(PF_INET, SOCK_STREAM, 0);
	hRSock = 0;
	
	memset(&hBAddr, 0, sizeof(PSOCKADDR_IN));
	memset(&hRAddr, 0, sizeof(PSOCKADDR_IN));
	
	portnumb = 8008;		//default

	//ClientSide Clear
	cSock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&cAddr, 0, sizeof(cAddr));


	isServerSide = false;
}

inline void SimpleSocket::setPortNumb(int port) { //번호 범위 점검 해줘야하나?
	portnumb = port;	
}

bool SimpleSocket::makeServer() {
	isServerSide = true;

	initSocket();
	SocKBind();

	return true;
}

bool SimpleSocket::JoinServer() {
	isServerSide = false;

	return true;
}



//private-Server Side
void SimpleSocket::initSocket() {
	hBAddr.sin_family		= AF_INET;
	hBAddr.sin_addr.s_addr = htonl(INADDR_ANY);	//서버 ip = 현재 PC IP로 설정
	hBAddr.sin_port = htons(SimpleSocket::portnumb);
}

bool SimpleSocket::SocKBind() {
	bind(hBSock, (SOCKADDR*)&hBAddr, sizeof(hBAddr));
		
	// 접속 받을수 있게
	listen(hBSock, 5);	// 접속대기 5		

	// 연결 수락
	szRAddr = sizeof(hRSock);
	hRSock = accept(hBSock, (SOCKADDR*)&hRAddr, &szRAddr);
	// 클라이언트와 통신 수립시 필요	

	return true;
}

bool SimpleSocket::CloseSocket() {
	closesocket(hRSock);
	closesocket(hBSock);
	WSACleanup();

	return true;
}

//private-Client Side
void SimpleSocket::initConnect() {
	cAddr.sin_family = AF_INET;
	cAddr.sin_port = htons(SimpleSocket::portnumb);	
}

bool SimpleSocket::ClientBind() {
	inet_pton(AF_INET, setOppositIP(), &cAddr.sin_addr.s_addr);


	return true;
}

char * SimpleSocket::setOppositIP() {
	return const_cast<char *>(ServerIP.c_str());
}