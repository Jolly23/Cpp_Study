// SOCKET����ͨѶ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>
#include <iostream>
using namespace std;

const int PORT = 8008;

int main(int argc, char* argv[])
{
	WSADATA wd;
	int n = WSAStartup(0x0202,&wd);		//����

/////////////////////////////////////////////////////////////////////
	SOCKET sock = socket(AF_INET,SOCK_DGRAM,0);
	if(sock == INVALID_SOCKET)
	{
		cout << "SOCKET�׽��ִ���ʧ�ܣ�" << endl;
		cout << "�������=" << WSAGetLastError() << endl;
		return -1;
	}

/////////////////////////////////////////////////////////////////////
	sockaddr_in sa = {AF_INET};//{AF_INET,PORT};			//��ַ��Ϣ const struct sockaddr FAR*  name
															//�ͻ��ˣ����Ͷˣ� ���Բ��󶨷��Ͷ˿ڣ�PORT����д0��д
	sockaddr_in sself = {0};
	int sLen = sizeof(sself);

	n = bind (sock,(sockaddr*)&sa,sizeof(sa));
	if(n == SOCKET_ERROR)
	{
		cout << "Bind�󶨶˿�ʧ�ܣ�" << endl;
		cout << "�������=" << WSAGetLastError() << endl;
		return -1;
	}

/////////////////////////////////////////////////////////////////////
							//���Ͷ�!!

	n = getsockname(sock,(sockaddr*)&sself,&sLen);		//�ɻ�ȡ�˿�
	cout << "�˿� = " << htons(sself.sin_port) << endl;
	sockaddr_in sa1 = {AF_INET,8009};
	sa1.sin_addr.S_un.S_addr = inet_addr("10.0.2.15");
	char s[256];
	cout << "���Ͷˣ�" <<endl;
	while(true)
	{
		cout << "������Ҫ���͵����ݣ�" ;
		gets(s);
		sendto(sock,s,strlen(s)+1,0,(sockaddr*)&sa1,sizeof(sa1));
	}
/////////////////////////////////////////////////////////////////////
	return 0;
}
//10.54.1.251
//10.0.2.15