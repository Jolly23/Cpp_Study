// PtrFuncTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <process.h>
#include <conio.h>


using namespace std;
void main()
{
	unsigned int a ,b;
	unsigned int &ra = a;

	cout << "Hallo,C++!" << endl;

	cout << "输入两个数字：";

	cin  >> ra >> b ;

	cout << a << "\t" << b << endl;
}