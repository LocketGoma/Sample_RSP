#pragma once
#include "Resource.h"
#include <sys/types.h>
#include <winsock.h>


//https://stackoverflow.com/questions/35019684/socket-programming-simple-chat-c
//https://m.blog.naver.com/PostView.nhn?blogId=tmone1&logNo=10181445622&proxyReferer=https%3A%2F%2Fwww.google.com%2F

//실제 "환경 대응"식 작업시에는, unix 기반에서는 sys/socket.h, windows 기반에서는 winsock를 사용하면 된다.
// = 두 환경을 비교, 대응할 수 있는 방식으로 작성해야 할 것