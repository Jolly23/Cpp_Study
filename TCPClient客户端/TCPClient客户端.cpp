// TCPClient客户端.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Winsock2.h>
#include <iostream>
using namespace std;
#pragma comment(lib,"ws2_32.lib")
const int ServerPort = 45611;
//TCP客户端
int main(int argc, char* argv[])
{
	WSADATA wd;
	WSAStartup(0x0202,&wd);
	
	SOCKET sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock == INVALID_SOCKET){
		cout << "Socket Error:" << WSAGetLastError() << endl;
		return -1;
	}

////////////////////////////////////////////////////////////////
	sockaddr_in sa = {AF_INET,htons(ServerPort)};	 //服务器地址信息
	sa.sin_addr.S_un.S_addr = inet_addr("10.0.2.15");//端口、IP
////////////////////////////////////////////////////////////////

	int nRes = connect(sock,(sockaddr*)&sa,sizeof(sa));
	if(nRes < 0){
		cout << "Connect Error:" << WSAGetLastError() << endl;
		return -1;
	}

	cout << "客户端：" << endl;
	char s[256];
	while(true)
	{
		cin >> s;
		send(sock,s,strlen(s),0);
	}
	
	return 0;
}
