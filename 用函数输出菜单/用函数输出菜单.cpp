// �ú�������˵�.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

int Menu()
{
	int c;
	puts("*********************");
	puts("1.�������");
	puts("2.�޸�����");
	puts("3.ɾ������");
	puts("0.�˳�����");
	puts("*********************");
	printf("��ѡ��");
	
	c=getch();
	
	return c;
}


int main(int argc, char* argv[])
{
	int mode=Menu();
	return 0;
}
