// CStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	CStack<double> s;
	int i = 0;
	double t;
	while(i < 10)
		s.push(i*0.672*i++);
	i = 0;
	while(s.pop(t))
	{
		if(s.isEmpty() == true)
			break;
		cout << t << endl;
	}

	return 0;
}
