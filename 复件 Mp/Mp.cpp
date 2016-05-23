// Mp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Map1.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	Stud s0 = {1506,"s0"},s1 = {12,"s1"},s2 = {352,"s2"},s3 = {57,"s3"},s4 = {274,"s4"},
		 s5 = {253,"s5"},s6 = {156,"s6"},s7 = {199,"s7"},s8 = {486,"s8"},s9 = {615,"s9"};
	CMap m;
	int i = 0;
	m.SetAt(s0);
	m.SetAt(s1);
	m.SetAt(s2);
	m.SetAt(s3);
	m.SetAt(s4);
	m.SetAt(s5);
	m.SetAt(s6);
	m.SetAt(s7);
	m.SetAt(s8);
	//m.SetAt(s9);
	Stud stud;
	if(m.LookUp(1506,stud))
	{
		cout << "找到了！" << endl;
		cout << "学号：" << stud.nNumb << "\t姓名：" << stud.sName << endl;
	}
	else
		cout << "未找到！" << endl;

	Stud &rst = m[253];
	cout << "学号：" << rst.nNumb  << "\t姓名：" << rst.sName << endl;
	cout << "打印全部：" << endl;
	m.PrintAll();
	return 0;
}

