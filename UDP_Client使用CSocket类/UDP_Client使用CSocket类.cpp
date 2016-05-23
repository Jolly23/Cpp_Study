// UDP_Client使用CSocket类.cpp : Defines the entry point for the console application.
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
		cout << "Creat函数错误：" << WSAGetLastError() << endl;
		return -1;
	}
	
	char sSend[256];
	cout << "客户端" << endl;
	while(true)
	{
		cout << "请输入要发送的内容：" ;
		gets(sSend);
		sock.SendTo(sSend,strlen(sSend),ServerPort,"10.0.2.15");
	}


	return 0;
}
