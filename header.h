#pragma once

// 소켓 생성에 쓰이는 inet_addr 함수에 대한 경고를 없애줌
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
// WS2tcpip.h 헤더 추가후 inet_addr() 대신 inet_pton() 함수 사용
//#include <WS2tcpip.h>
#include <iostream>
#include <WinSock2.h>
#include <thread>





using std::cout;
using std::endl;