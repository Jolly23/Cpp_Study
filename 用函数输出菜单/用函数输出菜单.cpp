// 用函数输出菜单.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

int Menu()
{
	int c;
	puts("*********************");
	puts("1.浏览数据");
	puts("2.修改数据");
	puts("3.删除数据");
	puts("0.退出程序");
	puts("*********************");
	printf("请选择：");
	
	c=getch();
	
	return c;
}


int main(int argc, char* argv[])
{
	int mode=Menu();
	return 0;
}
