// SOCKET网络通讯.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>
#include <iostream>
using namespace std;

const int PORT = 8009;

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
	sockaddr_in sa = {AF_INET,PORT};			//地址信息 const struct sockaddr FAR*  name
	n = bind (sock,(sockaddr*)&sa,sizeof(sa));
	if(n == SOCKET_ERROR)
	{
		cout << "Bind绑定端口失败！" << endl;
		cout << "错误代码=" << WSAGetLastError() << endl;
		return -1;
	}

/////////////////////////////////////////////////////////////////////
	/*              //发送！
	sockaddr_in sa1 = {AF_INET,PORT};
	sa1.sin_addr.S_un.S_addr = inet_addr("10.0.2.15");
	sendto(sock,"Hallo,World!",strlen("Hallo,World!"),0,(sockaddr*)&sa1,sizeof(sa1));
*/
/////////////////////////////////////////////////////////////////////
					//接收！
	sockaddr_in sfrom = {0};
	int nLen = sizeof(sfrom);
	char s[256];
	int i = 1;
	cout << "接收端：" <<endl;
	while( (recv(sock,s,sizeof(s),0) )>0)
	{
//		getpeername(sock,(sockaddr*)&sfrom,&nLen);
		cout << i++ << ": 发送方IP:" << inet_ntoa(sfrom.sin_addr) <<"端口：" << sfrom.sin_port << ": " << s << endl;
	}
	cout << "错误码=" << WSAGetLastError() << endl;
/////////////////////////////////////////////////////////////////////
	return 0;
}
/*
struct sockaddr_in {		
        short   sin_family;				// = AF_INET  //UDP、TCP总称
        u_short sin_port;
        struct  in_addr sin_addr;
        char    sin_zero[8];
};
*/