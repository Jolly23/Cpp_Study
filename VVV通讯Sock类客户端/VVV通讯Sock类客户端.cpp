// VVVͨѶSock��ͻ���.cpp : Defines the entry point for the console application.
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
		cout << "�ͻ���IP=" << sIP << "\t�˿�" << nPort << endl;
	else
		cout << "GetSockNameʧ�ܣ�Error=" << WSAGetLastError() << endl;

	if(sock.GetPeerName(sIP,nPort))
		cout << "������IP=" << sIP << "\t�˿�" << nPort << endl;
	else
		cout << "GetPeerNameʧ�ܣ�Error="  << WSAGetLastError() << endl;
}

int main(int argc, char* argv[])
{
	SockJolly sock;
	if(!sock.Create())
	{
		cout << "�˿ڴ���ʧ�ܣ�Error=" << WSAGetLastError() << endl;
		return -1;
	}

	IP(sock);

	if(!sock.Connect("10.0.2.15",10150))
	{
		cout << "����������ʧ�ܣ�Error=" << WSAGetLastError() << endl;
		return -1;
	}

	IP(sock);

	sock.Send("sb������",strlen("sb������"));
	return 0;
}
