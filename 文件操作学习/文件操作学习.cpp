// 文件操作学习.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <process.h>

void main()
{
	FILE *fp=fopen("ReadMe.txt","r");
	if(fp == NULL)
	{
		puts("fault");
	}
	else
	{
		puts("Succeed");
		char c;
		int i=0;
		while( fread(&c,1,sizeof(c),fp) > 0 )
		{
			printf("%02X  ",c);
			++i;
			if( i%8 == 0)
				printf("\n");
		}
		printf("\n共有%d个字节\n",i);
		fclose(fp);			
	}
	system("pause");
	
	/*
	FILE *p1 = fopen("c:\\1.txt","w");
	FILE *p2 = fopen("c:\\2.txt","r");
	int a[] = {58,213,69,-99};//-1;
	fwrite(&a,sizeof(a),1,p1);
	fclose(p1);
	*/
	
}
