#pragma once
#include "header.h"
#include <list>

class SocketServer
{
private:
	
	// WSA 함수용, 소켓의 버전을 관리하는 구조체
	WORD m_wVersionRequested;
	WSADATA m_wsaData;

	// IPv4의 주소 체계를 나타내는 구조체
	SOCKADDR_IN m_serverAddress;
	SOCKADDR_IN m_clientAddress;

	// 소켓
	SOCKET m_server;
	std::list<SOCKET> m_client;
	// 통신
	int m_bytesSent;
	char m_buf[255];

public:
	SocketServer();
	~SocketServer();
};

