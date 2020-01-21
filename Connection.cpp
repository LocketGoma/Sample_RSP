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

inline void SimpleSocket::setPortNumb(int port) { //��ȣ ���� ���� ������ϳ�?
	portnumb = port;	
}



//private 
void SimpleSocket::initSocket() {
	hBAddr.sin_family		= AF_INET;
	hBAddr.sin_addr.s_addr = htonl(INADDR_ANY);	//���� ip = ���� PC IP�� ����
	hBAddr.sin_port = htons(SimpleSocket::portnumb);
}

bool SimpleSocket::connection() {
	bind(hBSock, (SOCKADDR*)&hBAddr, sizeof(hBAddr));
		
		// ���� ������ �ְ�
	listen(hBSock, 5);	// ���Ӵ�� 5
		

	// ���� ����
	//szClntAddr = sizeof(clntAddr);
	//hRSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);	// Ŭ���̾�Ʈ�� ��� ������ �ʿ�

	

	return true;

}