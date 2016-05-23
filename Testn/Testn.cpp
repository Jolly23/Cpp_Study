// Testn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class CTest
{
	CTest()
	{}
	CTest(int n)
	{}
	CTest(const CTest &t)
	{}
};

void Print(int n,int Max)
{
	if(n>=Max)
		return;
	cout << n ;
	Print(n+1,Max++);
}
int main(int argc, char* argv[])
{
	Print(0,INT_MAX);
	return 0;

	//qwewudbjfbjabfbfbafbhafbabfhdfjnsnfnajf.adaf
}
