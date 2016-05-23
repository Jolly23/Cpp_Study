// CString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "String.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	CString s0 = "zhaolei";
	CString s1;
	CString s2('x',6);
	CString s3("zhaolei3364868616848648",11);
	CString s4 = "Test____________";
	CString s5;

	s1 = s0;

	s1 += "666";
	s0 += "777";
	
	s4 += s0;

	s5 = s1 + s2;

	cout << "0. " << (const char*)s0  << "\t长度 = " << s0.GetLength() << endl;
	cout << "1. " << (const char*)s1  << "\t长度 = " << s1.GetLength() << endl;
	cout << "2. " << (const char*)s2  << "\t长度 = " << s2.GetLength() << endl;
	cout << "3. " << (const char*)s3  << "\t长度 = " << s3.GetLength() << endl;
	cout << "4. " << (const char*)s4  << "\t长度 = " << s4.GetLength() << endl;
	cout << "5. " << (const char*)s5  << "\t长度 = " << s5.GetLength() << endl;

	return 0;
}
