#include "SocketServer.h"

SocketServer::SocketServer()
{
	m_wVersionRequested = MAKEWORD(1, 1);
	if (0 != WSAStartup(m_wVersionRequested, &m_wsaData))
	{
		cout << "WSAStartup error " << WSAGetLastError() << "\n";
		WSACleanup();
		return;
	}

	m_serverAddress.sin_family = AF_INET; // address family internet
	m_serverAddress.sin_port = htons(4400);
	m_serverAddress.sin_addr.s_addr = inet_addr(INADDR_ANY);
	

	
}


SocketServer::~SocketServer()
{
}
