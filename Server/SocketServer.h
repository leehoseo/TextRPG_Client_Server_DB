#pragma once
#include "header.h"
#include <list>

class SocketServer
{
private:
	
	// WSA �Լ���, ������ ������ �����ϴ� ����ü
	WORD m_wVersionRequested;
	WSADATA m_wsaData;

	// IPv4�� �ּ� ü�踦 ��Ÿ���� ����ü
	SOCKADDR_IN m_serverAddress;
	SOCKADDR_IN m_clientAddress;

	// ����
	SOCKET m_server;
	std::list<SOCKET> m_client;
	// ���
	int m_bytesSent;
	char m_buf[255];

public:
	SocketServer();
	~SocketServer();
};

