// STUD_AR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Student.h"
#include <iostream>

void main()
{
	CStudent AutoRun;
	while(true)
	{
		AutoRun.Load();
		AutoRun.Menu();
	//	AutoRun.Save();		��Ŀ��ɺ󣬴˺��������� �˳�������
	}
}
