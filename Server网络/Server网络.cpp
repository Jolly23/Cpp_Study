// Server网络.cpp : Defines the entry point for the console application.
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
	sockaddr_in sa = {AF_INET,htons(PORT)};
	int nLen = sizeof(sa);
	int nRes = bind(sock,(sockaddr*)&sa,sizeof(sa));
	if(nRes == SOCKET_ERROR){
		cout << "bind函数失败，错误代码=" << WSAGetLastError() << endl;
		return;
	}
	/////////////////////////////////////////////////////////////////////
	//Step4:
	listen(sock,5);
	SOCKET socka = accept(sock,(sockaddr*)&sa,&nLen);	//收发数据3
	if(socka == INVALID_SOCKET){
		cout << "Accept函数错误，错误代码=" << WSAGetLastError() << endl;
		return;
	}
	//正常情况：
	cout << "有人连接进来：" << inet_ntoa(sa.sin_addr) << "—" << htons(sa.sin_port) << endl;
	char sAccept[1024];
	while( (nRes = recv(socka,sAccept,sizeof(sAccept)-1,0)) > 0)
	{
		sAccept[nRes] = '\0';
		cout << sAccept << endl;
	}
	if(WSAGetLastError() == 10054)
		cout << "对方已断开连接！" << endl;
	system("pause");
}
