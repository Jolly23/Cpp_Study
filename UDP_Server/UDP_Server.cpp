// UDP_Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>
#include <iostream>
using namespace std;
//����
#pragma comment(lib,"ws2_32.lib")
const unsigned short PORT = 8009;	//����˿�
int main(int argc, char* argv[])
{
	WORD wVer = MAKEWORD(2,2);//����汾��    //0x0202	//2.2�汾   //С����ǰ(�汾�Ÿ�λ)-��16���������
	WSADATA wd;
	
	int n = WSAStartup(wVer,&wd);	//WSAStartup:����ֵΪ�ɹ���0�� �� ������룻
	if(n)
	{
		cout << "WSAStartup��������" << endl;
		return -1;
	}

	SOCKET sock = socket(AF_INET,SOCK_DGRAM,0);
	if(sock == INVALID_SOCKET)
	{
		cout << "SOCKET��������" << WSAGetLastError() << endl;
		return -1;
	}
	
	sockaddr_in sa = {AF_INET,htons(PORT)};

//	sa.sin_addr.S_un.S_addr = inet_addr("10.0.2.15");	//��ָ�����ȫ��IP����ȫ�棡
	n = bind(sock,(sockaddr*)&sa,sizeof(sa));			//����һ���µĶ˿ڣ�ռ�ô˶˿�
	if(n == SOCKET_ERROR)
	{
		cout << "Bind�������󣬴����룺" << WSAGetLastError() << endl;
		return -1;
	}
	else
		cout << "�˿ڷ����ɹ���" << PORT << endl;
	
	cout << "���նˣ�" << endl;
	char s[1000];
	while((n = recv(sock,s,strlen(s)+1,0,(sockaddr*)&sa,(int*)sizeof(sa)))>0)
	{
		cout << s << endl;
	}

	return 0;
}
