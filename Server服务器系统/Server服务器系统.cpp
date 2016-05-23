// Server服务器系统.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Students.h"

CStudents CStudents::st;

int main(int argc, char* argv[])
{
	CStudents::st.Start();
	return 0;
}
