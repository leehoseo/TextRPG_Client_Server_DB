#include "SocketServer.h"
#include <process.h>

SocketServer::SocketServer()
{
	Init();
}

SocketServer::~SocketServer()
{
}


bool SocketServer::Init()
{
	m_wVersionRequested = MAKEWORD(1, 1);
	if (0 != WSAStartup(m_wVersionRequested, &m_wsaData))
	{
		cout << "WSAStartup error " << WSAGetLastError() << endl;
		WSACleanup();
		return false;
	}

	memset(&m_serverAddress, 0, sizeof(m_serverAddress));
	m_serverAddress.sin_family = AF_INET; // address family internet
	m_serverAddress.sin_port = htons(4400);
	m_serverAddress.sin_addr.s_addr = htons(INADDR_ANY);
	


	m_server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if ( INVALID_SOCKET == m_server)
	{
		cout << "Socket error" << WSAGetLastError() << endl;
		WSACleanup();
		return false;
	}

	if (SOCKET_ERROR == bind(m_server, reinterpret_cast<SOCKADDR *>(&m_serverAddress), sizeof(m_serverAddress)))
	{
		cout << "Binding failed Error code : " << WSAGetLastError() << endl;
		WSACleanup();
		return false;
	}

	cout << "Waiting for client..." << endl;
	listen(m_server, 5);

	//_beginthread(Accept, 0, NULL);

	return true;
}

void SocketServer::Accept()
{
	while (true)
	{
		int xx = sizeof(m_clientAddress);
		SOCKET client = accept(m_server, reinterpret_cast<SOCKADDR *>(&m_clientAddress), &xx);
		cout << "Connection established. New socket num is " << client << endl;
		m_client.push_back(client);
	}
}
