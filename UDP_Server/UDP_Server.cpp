// UDP_Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>
#include <iostream>
using namespace std;
//连接
#pragma comment(lib,"ws2_32.lib")
const unsigned short PORT = 8009;	//定义端口
int main(int argc, char* argv[])
{
	WORD wVer = MAKEWORD(2,2);//网络版本号    //0x0202	//2.2版本   //小数点前(版本号高位)-在16进制数后边
	WSADATA wd;
	
	int n = WSAStartup(wVer,&wd);	//WSAStartup:返回值为成功（0） 或 错误代码；
	if(n)
	{
		cout << "WSAStartup函数错误！" << endl;
		return -1;
	}

	SOCKET sock = socket(AF_INET,SOCK_DGRAM,0);
	if(sock == INVALID_SOCKET)
	{
		cout << "SOCKET函数错误：" << WSAGetLastError() << endl;
		return -1;
	}
	
	sockaddr_in sa = {AF_INET,htons(PORT)};

//	sa.sin_addr.S_un.S_addr = inet_addr("10.0.2.15");	//不指定则绑定全部IP，更全面！
	n = bind(sock,(sockaddr*)&sa,sizeof(sa));			//发布一个新的端口，占用此端口
	if(n == SOCKET_ERROR)
	{
		cout << "Bind函数错误，错误码：" << WSAGetLastError() << endl;
		return -1;
	}
	else
		cout << "端口发布成功！" << PORT << endl;
	
	cout << "接收端：" << endl;
	char s[1000];
	while((n = recv(sock,s,strlen(s)+1,0,(sockaddr*)&sa,(int*)sizeof(sa)))>0)
	{
		cout << s << endl;
	}

	return 0;
}
