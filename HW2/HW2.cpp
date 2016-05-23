// HW2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OutPut.h"
#include "Input.h"
#include <iostream>
using namespace std;
#define ENDL '\n'
struct DATA
{
	int a;
	char b;
	float c;
	char d[20];
};
void operator<< (ostream &cout,DATA &d)
{
	cout << d.a << "\t" << d.b  << "\t" << d.c  << "\t" << d.d << ENDL;
	//想要的输出方式；
}

int main(int argc, char* argv[])
{
	CInput in;
	OutPut out;
	struct DATA dd = {16,'c',6.6f,"zhaoleu"};
	int i = 0;
	out << "你哈" << 66 << ENDL << &i << ENDL;
//	in >> i;
	out << i <<ENDL;
	cout << dd ;
	return 0;
}
