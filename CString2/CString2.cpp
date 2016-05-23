// CString2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "String.h"
#include <iostream>
using namespace std;

void main()
{
	CString s  = "abcdefg12cd3";
	CString s1 = "abcdefg123";
//	CString s(str,3);
//	s = "aaa";
//	s1 = "zzz";
	s1 += s;
	cout << s1.m_pData <<  endl;
	cout << s1.m_nLength<< endl;
	if(s1 > s)
		cout << "成立 "<< endl;
	else
		cout << "不成立" << endl;

//	CString ss = s.Right(6);
//	s.MakeReverse();
	int P = s.Find("cde");
	cout << s.m_pData << endl;
	cout << s.m_nLength<< endl;
	cout << P << endl;
}
