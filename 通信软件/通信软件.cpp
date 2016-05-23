// 通信软件.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>
#include <process.h>
#include <iostream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

//unsigned long _beginthread( void( __cdecl *start_address )( void * ), unsigned stack_size, void *arglist );
const int PORT = 8008;

SOCKET sock;

void RecvMain(void *pSock)		//多线程接收端
{
	//接收！
	SOCKET sock = (SOCKET)pSock;
	sockaddr_in sfrom = {0};
	int nLen = sizeof(sfrom);
	char GetString[256];
	int i = 1;
	while(true)
	{
		recvfrom(sock,GetString,sizeof(GetString),0,(sockaddr*)&sfrom,&nLen);
		cout << "接收" << i++ << ": 发送方IP:" << inet_ntoa(sfrom.sin_addr) 
			 <<"端口：" << htons(sfrom.sin_port) << ": " << GetString << endl;
	}
}

int main(int argc, char* argv[])
{
	WSADATA wd;
	int n = WSAStartup(0x0202,&wd);		//启动
	sock = socket(AF_INET,SOCK_DGRAM,0);
/////////////////////////////////////////////////////////////////////
	if(sock == INVALID_SOCKET)
	{
		cout << "SOCKET套接字创建失败！" << endl;
		cout << "错误代码=" << WSAGetLastError() << endl;
		return -1;
	}

/////////////////////////////////////////////////////////////////////
	sockaddr_in sa = {AF_INET,htons(PORT)};//{AF_INET,PORT};		
	//地址信息 const struct sockaddr FAR*  name
	//客户端（发送端） 可以不绑定发送端口，PORT部分写0或不写
	sockaddr_in sself = {0};

	int sLen = sizeof(sself);

	n = bind (sock,(sockaddr*)&sa,sizeof(sa));
	if(n == SOCKET_ERROR)
	{
		cout << "Bind绑定端口失败！" << endl;
		cout << "错误代码=" << WSAGetLastError() << endl;
		return -1;
	}

/////////////////////////////////////////////////////////////////////
	_beginthread(RecvMain,1024*1024,(void*)sock);				//启动多线程接收端
/////////////////////////////////////////////////////////////////////

	//发送端!!
	n = getsockname(sock,(sockaddr*)&sself,&sLen);		//可获取端口
	cout << "本机IP = " << inet_ntoa(sself.sin_addr) << "\t本机端口 = " << htons(sself.sin_port) << endl;
	
	int ToPort = 0;
	char ToIP[20] = {0};
	cout << "请输入对方IP：";
	cin  >> ToIP;

	sockaddr_in SATO = {AF_INET,htons(PORT)};
	SATO.sin_addr.S_un.S_addr = inet_addr(ToIP);
	char GetString[256];
	while(true)
	{
		cout << "请输入要发送的内容：" ;
		gets(GetString);
		sendto(sock,GetString,strlen(GetString)+1,0,(sockaddr*)&SATO,sizeof(SATO));
		Sleep(16);
	}
/////////////////////////////////////////////////////////////////////
	return 0;
}
//目标IP
//10.54.1.251
//10.0.2.15

//char my_ip[13];
//strcpy(my_ip,inet_ntoa(user_addr.sin_addr));  
//printf("my_ip:%s\n",inet_ntoa(user_addr.sin_addr)); 