#pragma once
#include "Resource.h"
#include <sys/types.h>
#include <winsock.h>


//https://stackoverflow.com/questions/35019684/socket-programming-simple-chat-c
//https://m.blog.naver.com/tmone1/10181445622

//���� "ȯ�� ����"�� �۾��ÿ���, unix ��ݿ����� sys/socket.h, windows ��ݿ����� winsock�� ����ϸ� �ȴ�.
// = �� ȯ���� ��, ������ �� �ִ� ������� �ۼ��ؾ� �� ��

//�׷��ϱ�... �������̵� �ϳ� ����� Ŭ���̾�Ʈ ���̵� ���� ���� �ǰڳ�

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
		inline void setPortNumb(int port);		//��Ʈ��ȣ ����
		bool JoinServer();		//���� ������

	private:
		WSADATA wsaData;
		bool isServerSide;		//������Ʈ (=���Ӵ��)����, Ŭ����Ʈ(=���ӿ�û)����.
		void initSocket();		//�ʱ����� ����.. ������ üũ�ϰ������.
		bool connection();





};

/*
struct sockaddr_in {
		short   sin_family;
		u_short sin_port;
		struct  in_addr sin_addr;
		char    sin_zero[8];
};

*/