// CStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	CStack s(8);
	int i = 0, t;
	while(i < 15)
		s.push(i++);
	i = 0;
	while(s.pop(t))
	{
		if(s.isEmpty() == true)
			break;
		cout << t << endl;
	}

	return 0;
}
