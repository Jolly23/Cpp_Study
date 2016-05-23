// Template项目Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define COUNT(x) sizeof(x)/sizeof(x[0])		//宏函数

struct STUD
{
	int  nNumb;
	char sName[20];
	float fMath;

	operator float()				//以float调用，返回值为成绩
	{	return fMath;	}
	operator int()					//以int  调用，返回值为学号
	{	return nNumb;	}
};

ostream& operator<<(ostream& o, const STUD& s)						//输出函数运算符重载，直接cout结构体
{
	cout << s.nNumb << "\t" <<s.nNumb << "\t" << s.fMath << endl;
	return o;
}

template <class T>							//模板
void Sort(T *stud , int n)
{
	int i = 0, j = 0 ,nMin = 0;
	while(i < n-1)
	{
		j = i+1;
		nMin = i;
		while( j < n)
		{
			if((int)stud[j] < (int)stud[nMin])	//(int) 意味着 通过学号排序，若改为(float)，则通过成绩排序
				nMin = j;
			++j;
		}
		if(nMin != i)
		{
			T t = stud[i];
			stud[i] = stud[nMin];
			stud[nMin] = t;
		}
		++i;
	}
}

template <class T>
void Print(T *stud , int n)
{
	int i = 0;
	while(i<n)
	{
		cout << stud[i] <<endl;
		++i;
	}
}

int main(int argc, char* argv[])
{
	STUD stud[] = {{2001,"赵磊",95.5f},{2009,"李丽珍",35.5f},{1005,"对不起",68},{2015,"刘兰芳",35.1f}};
	Sort<STUD>(stud,COUNT(stud));
	Print<STUD>(stud,COUNT(stud));
	return 0;
}
