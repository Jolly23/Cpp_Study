// ServerClient网络客户端.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>
#include <process.h>
#include <iostream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
//TCP
const int PORT = 10150;

void main()
{
	/////////////////////////////////////////////////////////////////////
	//Step1:
	WSADATA wd;
	WSAStartup(0x0202,&wd);
	/////////////////////////////////////////////////////////////////////
	//Step2:
	SOCKET sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock == INVALID_SOCKET){
		cout << "创建SOCKET失败，错误代码=" << WSAGetLastError() << endl;
		return;
	}
	/////////////////////////////////////////////////////////////////////
	//Step3:
	sockaddr_in sa = {AF_INET};
	int nLen = sizeof(sa);
	int nRes = bind(sock,(sockaddr*)&sa,sizeof(sa));
	if(nRes == SOCKET_ERROR){
		cout << "bind函数失败，错误代码=" << WSAGetLastError() << endl;
		return;
	}
	/////////////////////////////////////////////////////////////////////
	//Step4:
	char ToIP[20];
	cout << "请输入要连接的服务器IP：" ;
	cin  >> ToIP;
	sa.sin_addr.S_un.S_addr = inet_addr(ToIP);
	sa.sin_port = htons(PORT);
	nRes = connect(sock,(sockaddr*)&sa,sizeof(sa));
	if(nRes == SOCKET_ERROR){
		cout << "连接服务器失败，错误代码=" << WSAGetLastError() << endl;
		return;
	}
	/////////////////////////////////////////////////////////////////////
	//Step5:
	//服务器连接成功，开始发送数据
	char sSend[256];
	while(true)
	{
		fflush(stdin);
		cout << "请输入发送数据：";
		gets(sSend);
		send(sock,sSend,strlen(sSend)+1,0);
	}
	system("pause");
}
