// Testpaisheng.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A
{
public:
	int ax ;
	int ay ;
	void PrintA()
	{
		cout << "A成员函数" << endl;
	}
	A()
	{
		ax = 0;
		ay = 0;
	}
	A(int m, int n)
	{
		ax = m;
		ay = n;
	}
};

class B:public A
{
public:
	B():A(11,22)
	{}
	int bx ;
	int by ;
	void PrintB()
	{
		cout << "B成员函数" << endl;
	}
};

class C:public B
{
public:
	C()
	{
	
	}
	int cx ;
	int cy ;
	void PrintC()
	{
		cout << "C成员函数" << endl;
	}
};


int main(int argc, char* argv[])
{
	A a;
	a.PrintA();
	a.ax = 2;
	//////////////////
	B b;
	b.ax = 6;
	b.PrintB();
	//////////////////
	C c;
	c.cx = 12;
	c.PrintA();
	c.PrintB();
	c.PrintC();
	/////////////////
	A aa;
	B bb;
	C cc;
	
	return 0;
}
