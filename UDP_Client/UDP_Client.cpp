// UDP_Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>
#include <iostream>
using namespace std;
//����
#pragma comment(lib,"ws2_32.lib")
const unsigned short ServerPort = 8010;	//����˿�
int main(int argc, char* argv[])
{
	WORD wVer = MAKEWORD(2,2);//����汾��    //0x0202	//2.2�汾   //С����ǰ(�汾�Ÿ�λ)-��16���������
	WSADATA wd;
	
	int nError = WSAStartup(wVer,&wd);	//WSAStartup:����ֵΪ�ɹ���0�� �� ������룻
	if(nError)
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
	
	sockaddr_in sa = {AF_INET,htons(ServerPort)};
	sa.sin_port = htons(ServerPort);			//host to network (short)
	sa.sin_addr.S_un.S_addr = inet_addr("10.0.2.15");	//�󶨱���IP	//��ָ�����ȫ��IP����ȫ�棡
	nError = bind(sock,(sockaddr*)&sa,sizeof(sa));		//����һ���µĶ˿ڣ�ռ�ô˶˿�
	if(nError == SOCKET_ERROR)
	{
		cout << "Bind�������󣬴����룺" << WSAGetLastError() << endl;
		return -1;
	}
	else
		cout << "�˿ڷ����ɹ���" << ServerPort << endl;

	cout << "���Ͷˣ�" << endl;
	char s[1000];
	while(true)
	{
		gets(s);
		sendto(sock,s,strlen(s)+1,0,(sockaddr*)&sa,sizeof(sa));
	}

	return 0;
}
