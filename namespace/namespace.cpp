// namespace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <process.h>
#include <iostream>

using namespace std;
namespace ZHAOLEI
{
	void Test()
	{
		cout << " ÕÔÀÚ±àÐ´£¡" << endl;
	}
};

void Test()
{
	cout << " ¹«¹²ÇøÓò£¡" << endl;
}

int main(int argc, char* argv[])
{
	ZHAOLEI::Test();
   
	Test();
	
	::Test();
	
	system("pause");

	return;
}
