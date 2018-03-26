#pragma once
#include "../header.h"
#include <list>

// Client, Server 연결용
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
	// 생성자 소멸자, 복사대입, 복사 생성 막아놈
	SocketServer();
	~SocketServer();
	SocketServer operator=(const SocketServer&) = delete;
	SocketServer(const SocketServer&) = delete;

	// 소켓 생성
	bool Init();

	// 클라이언트 접속 대기
	void Accept();

};

