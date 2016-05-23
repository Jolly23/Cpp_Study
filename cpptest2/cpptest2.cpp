// cpptest2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory.h>
#define PI 3.141592
using namespace std;

/*
struct Function
{
float R;

float Mianji(float R)
{
	return PI*R*R;
}
		
float Zhouchang(float R)
{
	return 2*PI*R;
}
		  
void Input()
{
	cout << "请输入圆周长：" ;
	cin  >> R;
}
};
			
int main(int argc, char* argv[])
{
	Function R1;
	R1.Input();
	  cout << "圆周长为：" << R1.Zhouchang(R1.R) << endl;
			  cout << "圆面积为：" << R1.Mianji(R1.R) << endl;
			  return 0;
			  }
*/

struct STUD
{
	int nNumb;
	char sName[20];
	float ZongChengji;
	STUD()
	{
		memset(this,0,sizeof(STUD));
	}
};

struct SLi : STUD
{
	float shengwu;
	float huaxue;
	float wuli;
};

struct SWen : STUD
{
	float lishi;
	float zhengzhi;
	float dili;
};

int main()
{
	STUD s1;
}