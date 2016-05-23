// public_private.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stud.h"
#include <iostream>

int main(int argc, char* argv[])
{
	CStud list1,list2;
	
	int Sel;
	int d;

	do
	{
		cout << "请输入数据：" << endl;
		cin  >> d;
		
		cout << "请选择要存入的链表（1或2）" << endl;
		cin  >> Sel;

		if(Sel == 0)
			break;
		if(Sel == 1)
			list1.AddHead(d);
		if(Sel == 2)
			list2.AddHead(d);

		cout << "list1.Count = " << list1.GetCount() << endl;
		cout << "list2.Count = " << list2.GetCount() << endl;
	
	}while(1);

	return 0;
}
