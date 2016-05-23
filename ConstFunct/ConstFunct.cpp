// ConstFunct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin ;

class CTest
{
	int a,b;
	char s[20];

public:
	CTest()
	{
		a = 0,b = 0;
	}

	int GetA() const
	{	return a;	}

	void SetA(int a)
	{
		this ->a = a;
	}
};

int main(int argc, char* argv[])
{
	cout << "HiaHia!" << endl;
	int a = INT_MAX;
	cout << a <<endl;
	return 0;
}
