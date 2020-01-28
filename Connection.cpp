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


//Client Side
SimpleConnect::SimpleConnect() {
	//ClientSide Clear
	cSock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&cAddr, 0, sizeof(cAddr));

	portnumb = 8008;
}
void SimpleConnect::initConnect() {
	cAddr.sin_family = AF_INET;
	cAddr.sin_port = htons(SimpleConnect::portnumb);
}
bool SimpleConnect::ClientBind() {
	inet_pton(AF_INET, setOppositIP(), &cAddr.sin_addr.s_addr);
	connect(cSock, (SOCKADDR *)(&cAddr), sizeof(SOCKADDR_IN));
	

	return true;
}
bool SimpleConnect::CallingMessange() {
	std::string msg;
	recv(cSock, const_cast<char*>(msg.c_str()), sizeof(msg) - 1, 0);
	std::cout << "S : " <<msg << std::endl;


	return true;
}
char * SimpleConnect::setOppositIP() {
	return const_cast<char *>(ServerIP.c_str());
}



//Test

void SimpleSocket::test() {
	WSADATA		wsaData;
	SOCKET		hServSock, hClntSock;
	SOCKADDR_IN servAddr, clntAddr;

	short	port = 5001;
	int		szClntAddr;
	char	message[] = "Hello World!";

	// ���� �ʱ�ȭ, ���ϻ���ϱ��� �ʱ�ȭ �ؾ���
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");

	// TCP ���ϻ���
	hServSock = socket(PF_INET, SOCK_STREAM, 0);

	if (hServSock == INVALID_SOCKET)
		ErrorHandling("socket() error!");

	// ������ �ּ�����
	memset(&servAddr, 0, sizeof(servAddr));

	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);	// ���� PC IP�ּ� ���
	servAddr.sin_port = htons(port);		// ��Ʈ��ȣ

	// �ּ� ����
	if (bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		ErrorHandling("bind() error!");

	// ���� ������ �ְ�
	if (listen(hServSock, 5) == SOCKET_ERROR)	// ���Ӵ�� 5
		ErrorHandling("listen() error!");

	// ���� ����
	szClntAddr = sizeof(clntAddr);
	hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);	// Ŭ���̾�Ʈ�� ��� ��

	if (hClntSock == INVALID_SOCKET)
		ErrorHandling("accept() error!");

	
	int ans = 1;
	while (ans!=0) {	
		std::cin >> message;

		ans=send(hClntSock, message, sizeof(message), 0);
	}

	closesocket(hClntSock);
	closesocket(hServSock);
	WSACleanup();

}


void SimpleConnect::test() {
	WSADATA		wsaData;
	SOCKET		hSocket;
	SOCKADDR_IN servAddr;

	int		port = 5001;

	char	message[30] = {};
	int		strLen;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);

	if (hSocket == INVALID_SOCKET)
		ErrorHandling("hSocket() error!");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(port);
	inet_pton(AF_INET, "127.0.0.1", &servAddr.sin_addr.s_addr);

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		ErrorHandling("connect() error!");

	while (true) {
		strLen = recv(hSocket, message, sizeof(message) - 1, 0);
		
		if (strLen == -1)
			ErrorHandling("read() error!");
		
		if (message!="")
		printf("message from server: %s \n", message);

	}
	closesocket(hSocket);
	WSACleanup();

}
