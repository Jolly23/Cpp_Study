// TCPServer 服务器.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Winsock2.h>
#include <iostream>
using namespace std;
#pragma comment(lib,"ws2_32.lib")
const int SelfPort = 45611;
//TCP服务器
int main(int argc, char* argv[])
{
	WSADATA wd;
	WSAStartup(0x0202,&wd);
	
	SOCKET sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock == INVALID_SOCKET){
		cout << "Socket Error:" << WSAGetLastError() << endl;
		return -1;
	}

	sockaddr_in sa = {AF_INET,htons(SelfPort)};
	int nRes = bind(sock,(sockaddr*)&sa,sizeof(sa));

	listen(sock,5);

	char s[256];
	while(1)
	{
		SOCKET socka = accept(sock,NULL,NULL);
		while((nRes = recv(socka,s,sizeof(s),0)) > 0)
		{
			s[nRes] = '\0';
			cout << s << endl ;
		}
	}
	return 0;
}
