#pragma once
#include "Resource.h"
#include <sys/types.h>
#include <winsock.h>


//https://stackoverflow.com/questions/35019684/socket-programming-simple-chat-c
//https://m.blog.naver.com/PostView.nhn?blogId=tmone1&logNo=10181445622&proxyReferer=https%3A%2F%2Fwww.google.com%2F

//���� "ȯ�� ����"�� �۾��ÿ���, unix ��ݿ����� sys/socket.h, windows ��ݿ����� winsock�� ����ϸ� �ȴ�.
// = �� ȯ���� ��, ������ �� �ִ� ������� �ۼ��ؾ� �� ��