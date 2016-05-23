// Server多线程服务器M ulti_Thread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <process.h>
#include <Winsock2.h>
#include <iostream>
using namespace std;
#pragma comment(lib,"ws2_32.lib")
const int SelfPort = 45611;
//TCP服务器

void RecvProc(void *pSock);
PrintAddr(sockaddr_in sa);

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

	sockaddr_in sSelf = {0};
	int nLen = sizeof(sSelf);
//	getsockname(sock,(sockaddr*)&sSelf,&nLen);
//	PrintAddr(sSelf);

	char s[256];
	while(1)
	{
		SOCKET socka = accept(sock,NULL,NULL);
		getpeername(socka,(sockaddr*)&sSelf,&nLen);// 获取接入客户端信息
		PrintAddr(sSelf);
		_beginthread(RecvProc,1024*1024,(void*)socka);
	}
	return 0;
}

PrintAddr(sockaddr_in sa)
{
	cout << "IP = " << inet_ntoa(sa.sin_addr) << "\tPORT = " << htons(sa.sin_port) << "已接入服务器" << endl;
}

void RecvProc(void *pSock)
{
	SOCKET socka = (SOCKET)pSock;
	char s[256];
	int nRes;
	while( (nRes = recv(socka,s,sizeof(s)-1,0)) > 0 )
	{
		s[nRes] = '\0';
		cout << s << endl;
	}
}