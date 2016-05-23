// SOCKET网络通讯.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>
#include <iostream>
using namespace std;

const int PORT = 8008;

int main(int argc, char* argv[])
{
	WSADATA wd;
	int n = WSAStartup(0x0202,&wd);		//启动

/////////////////////////////////////////////////////////////////////
	SOCKET sock = socket(AF_INET,SOCK_DGRAM,0);
	if(sock == INVALID_SOCKET)
	{
		cout << "SOCKET套接字创建失败！" << endl;
		cout << "错误代码=" << WSAGetLastError() << endl;
		return -1;
	}

/////////////////////////////////////////////////////////////////////
	sockaddr_in sa = {AF_INET};//{AF_INET,PORT};			//地址信息 const struct sockaddr FAR*  name
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
							//发送端!!

	n = getsockname(sock,(sockaddr*)&sself,&sLen);		//可获取端口
	cout << "端口 = " << htons(sself.sin_port) << endl;
	sockaddr_in sa1 = {AF_INET,8009};
	sa1.sin_addr.S_un.S_addr = inet_addr("10.0.2.15");
	char s[256];
	cout << "发送端：" <<endl;
	while(true)
	{
		cout << "请输入要发送的内容：" ;
		gets(s);
		sendto(sock,s,strlen(s)+1,0,(sockaddr*)&sa1,sizeof(sa1));
	}
/////////////////////////////////////////////////////////////////////
	return 0;
}
//10.54.1.251
//10.0.2.15