// 文件操作学习.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <conio.h>

void main()
{
	char c[20];
	char a;
	int i=0;
	while(i<20)
	{
		a = getch();
		strcat(&a,c);
		putch(a);
		++i;
	}

}
