// TCP_Server使用CSocket类.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <afxsock.h>
#include <iostream>
using namespace std;

const int PORT = 49031;
int main(int argc, char* argv[])
{
	WSADATA wd;
	WSAStartup(0x0202,&wd);
	CSocket sock;
	BOOL b = sock.Create(PORT);
	if(!b){
		cout << "Creat函数错误：" << WSAGetLastError() << endl;
		return -1;
	}

	sock.Listen();

	CSocket socka;
	CString szIP;
	UINT nPort;
	char sAccept[256];
	int nRes;
	while(sock.Accept(socka))
	{
		while( nRes = socka.ReceiveFrom(sAccept,sizeof(sAccept)-1,szIP,nPort) )
		{
			sAccept[nRes] = '\0';
			cout << (const char*)szIP << "-" << nPort << ": " << sAccept << endl;			
		}
	}

	return 0;
}
