#include "Connection.h"
#include <cassert>
#include <iostream>


SimpleSocket::SimpleSocket() {
	assert(WSAStartup(MAKEWORD(2, 2), &wsaData) == 0);
		std::cout << "Error!" << std::endl;
		

	hBSock = socket(PF_INET, SOCK_STREAM, 0);
	hRSock = 0;
	memset(&hBAddr, 0, sizeof(PSOCKADDR_IN));
	memset(&hRAddr, 0, sizeof(PSOCKADDR_IN));

}
