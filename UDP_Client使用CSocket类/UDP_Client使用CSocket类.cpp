// UDP_Clientʹ��CSocket��.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <afxsock.h>
#include <iostream>
using namespace std;

const int ServerPort = 49152;
int main(int argc, char* argv[])
{
	WSADATA wd;
	WSAStartup(0x0202,&wd);
	CSocket sock;
	BOOL b = sock.Create(0,SOCK_DGRAM);
	if(!b){
		cout << "Creat��������" << WSAGetLastError() << endl;
		return -1;
	}
	
	char sSend[256];
	cout << "�ͻ���" << endl;
	while(true)
	{
		cout << "������Ҫ���͵����ݣ�" ;
		gets(sSend);
		sock.SendTo(sSend,strlen(sSend),ServerPort,"10.0.2.15");
	}


	return 0;
}
