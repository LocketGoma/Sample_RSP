#include "Connection.h"
#include <cassert>
#include <iostream>

//public
SimpleSocket::SimpleSocket() {
	//assert(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0);	
	//	std::cout << "Error!" << std::endl;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)		//==0�� �ϸ� Error�� �߰�, !=0�� �ϸ� ������...
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

inline void SimpleSocket::setPortNumb(int port) { //��ȣ ���� ���� ������ϳ�?
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
	hBAddr.sin_addr.s_addr = htonl(INADDR_ANY);	//���� ip = ���� PC IP�� ����
	hBAddr.sin_port = htons(SimpleSocket::portnumb);
}

bool SimpleSocket::SocKBind() {
	bind(hBSock, (SOCKADDR*)&hBAddr, sizeof(hBAddr));
		
	// ���� ������ �ְ�
	listen(hBSock, 5);	// ���Ӵ�� 5		

	// ���� ����
	szRAddr = sizeof(hRSock);
	hRSock = accept(hBSock, (SOCKADDR*)&hRAddr, &szRAddr);
	// Ŭ���̾�Ʈ�� ��� ������ �ʿ�	

	return true;
}

bool SimpleSocket::CloseSocket() {
	closesocket(hRSock);
	closesocket(hBSock);
	WSACleanup();

	return true;
}
bool SimpleSocket::SendingMessage() {
	std::string msg;
	std::cin >> msg;
	send(hRSock, const_cast<char *>(msg.c_str()), sizeof(msg), 0);


	return true;
}


//private-Client Side
void SimpleSocket::initConnect() {
	cAddr.sin_family = AF_INET;
	cAddr.sin_port = htons(SimpleSocket::portnumb);	
}

bool SimpleSocket::ClientBind() {
	inet_pton(AF_INET, setOppositIP(), &cAddr.sin_addr.s_addr);
	connect(cSock, (SOCKADDR *)(&cAddr), sizeof(SOCKADDR_IN));
	

	return true;
}
bool SimpleSocket::CallingMessange() {
	std::string msg;
	recv(cSock, const_cast<char*>(msg.c_str()), sizeof(msg) - 1, 0);
	std::cout << "S : " <<msg << std::endl;


	return true;
}

char * SimpleSocket::setOppositIP() {
	return const_cast<char *>(ServerIP.c_str());
}