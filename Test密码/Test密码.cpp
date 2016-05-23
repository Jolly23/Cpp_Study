// Test√‹¬Î.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int i = 0;
	char ch;
	char sNewAdminPass[32];
	memset(sNewAdminPass,0,sizeof(sNewAdminPass));

	while((ch = getch()) != '\r')
	{
		if(ch == '\b')
		{
			--i;
			cout << '\b';
			continue;
		}
		putchar('*');
		sNewAdminPass[i++] = ch;
	}
	sNewAdminPass[i] = '\0';
	cout << endl << sNewAdminPass << endl;
	system("pause");
	return 0;
}
