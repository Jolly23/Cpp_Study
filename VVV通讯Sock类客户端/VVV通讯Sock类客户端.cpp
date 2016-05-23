// VVV通讯Sock类客户端.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SockJolly.h"
#include <iostream>
using namespace std;

void IP(SockJolly &sock )
{
	char sIP[20];
	UINT nPort;

	if(sock.GetSockName(sIP,nPort))
		cout << "客户端IP=" << sIP << "\t端口" << nPort << endl;
	else
		cout << "GetSockName失败！Error=" << WSAGetLastError() << endl;

	if(sock.GetPeerName(sIP,nPort))
		cout << "服务器IP=" << sIP << "\t端口" << nPort << endl;
	else
		cout << "GetPeerName失败！Error="  << WSAGetLastError() << endl;
}

int main(int argc, char* argv[])
{
	SockJolly sock;
	if(!sock.Create())
	{
		cout << "端口创建失败！Error=" << WSAGetLastError() << endl;
		return -1;
	}

	IP(sock);

	if(!sock.Connect("10.0.2.15",10150))
	{
		cout << "服务器连接失败！Error=" << WSAGetLastError() << endl;
		return -1;
	}

	IP(sock);

	sock.Send("sb哈哈哈",strlen("sb哈哈哈"));
	return 0;
}
