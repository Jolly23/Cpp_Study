// Q.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.h"
#include <iostream>
using namespace std;

void main()
{
	CQueue<int> q(4);
	int i = 0;
	while(i < 5)
		q.push(++i);
	
	int t;
	while(q.pop(t))
	{
		cout << t << endl;
	}
}
