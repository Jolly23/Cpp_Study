// �쳣.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void F2(int n)
{
	throw 666;
}

void F1()
{
	int n;
	cout << "����һ������50��С��100������:" ;
	cin >> n;
	if(n <= 50  ||  n >= 100)
	{
		F2(n);
		throw "Hallo";
	}
	cout << "OK!" << endl;
}

int main(int argc, char* argv[])
{
	try{
		F1();
	}
	catch(int n)
	{
		cout << "�����쳣 n=" << n << endl;
	}
	catch(...)
	{
		cout << "�����쳣" << endl;
	}
	return 0;
}
