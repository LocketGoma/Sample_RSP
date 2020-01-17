#pragma once
#include "Resource.h"
#include <sys/types.h>
#include <winsock.h>


//https://stackoverflow.com/questions/35019684/socket-programming-simple-chat-c
//https://m.blog.naver.com/PostView.nhn?blogId=tmone1&logNo=10181445622&proxyReferer=https%3A%2F%2Fwww.google.com%2F

//���� "ȯ�� ����"�� �۾��ÿ���, unix ��ݿ����� sys/socket.h, windows ��ݿ����� winsock�� ����ϸ� �ȴ�.
// = �� ȯ���� ��, ������ �� �ִ� ������� �ۼ��ؾ� �� ��


class SimpleSocket {
	public:
		//SOCKET = uint
		SOCKET hBSock;		//'Server' ������
		SOCKET hRSock;		//'Client' ������
		SOCKADDR_IN hBAddr; //'Server' ������
		SOCKADDR_IN hRAddr; //'Client' ������

		int portnumb;		//�⺻ ��Ʈ��ȣ

		SimpleSocket();

		bool setOppositIP();
		bool setPortNumb();

	private:
		WSADATA wsaData;


		bool initSocket();		//�ʱ����� ����


};

/*
struct sockaddr_in {
		short   sin_family;
		u_short sin_port;
		struct  in_addr sin_addr;
		char    sin_zero[8];
};

*/