// TCP_Clientʹ��CSocket��.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <afxsock.h>
#include <iostream>
using namespace std;

const int ServerPort = 49031;
int main(int argc, char* argv[])
{
	WSADATA wd;
	WSAStartup(0x0202,&wd);
	CSocket sock;
	BOOL b = sock.Create();
	if(!b){
		cout << "Creat��������" << WSAGetLastError() << endl;
		return -1;
	}
	sock.Connect("10.0.2.15",ServerPort);
	
	char sSend[2048];
	while(true)
	{
		cout << "������Ҫ���͵����ݣ�";
		gets(sSend);
		sock.Send(sSend,strlen(sSend)+1);
	}
	return 0;
}
