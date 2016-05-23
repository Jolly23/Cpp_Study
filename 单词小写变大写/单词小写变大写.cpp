// 单词小写变大写.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>



int main(int argc, char* argv[])
{
	char c;
	do
	{
		c=getchar();
		putchar(toupper(c));
	}while(c!='\n');
}
	/*
	char c;
	do
	{
		
		
		c=getchar();
		if(c>='a'&&c<='z')	c-=32;
		putchar(c);
	}while(c!='#');
	
	return 0;
	*/