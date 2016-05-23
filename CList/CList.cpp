// CList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	CList list;
	
	list.AddTail(99);
	list.AddTail(2319);
	list.AddTail(141);
	list.AddHead(66);
	list.AddHead(214124);
	list.AddHead(21);

	POSITION pos = list.GetHeadPosition();
	cout << "³õÊ¼Í·µØÖ·£º" << pos << endl;

	while(pos)
	{
		cout << list.GetAt(pos) << endl;
		list.GetNext(pos);
	}
	cout << "Hallo,NewType!"<< endl;
	return 0;
}
