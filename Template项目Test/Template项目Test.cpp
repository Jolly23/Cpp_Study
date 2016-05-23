// Template��ĿTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define COUNT(x) sizeof(x)/sizeof(x[0])		//�꺯��

struct STUD
{
	int  nNumb;
	char sName[20];
	float fMath;

	operator float()				//��float���ã�����ֵΪ�ɼ�
	{	return fMath;	}
	operator int()					//��int  ���ã�����ֵΪѧ��
	{	return nNumb;	}
};

ostream& operator<<(ostream& o, const STUD& s)						//���������������أ�ֱ��cout�ṹ��
{
	cout << s.nNumb << "\t" <<s.nNumb << "\t" << s.fMath << endl;
	return o;
}

template <class T>							//ģ��
void Sort(T *stud , int n)
{
	int i = 0, j = 0 ,nMin = 0;
	while(i < n-1)
	{
		j = i+1;
		nMin = i;
		while( j < n)
		{
			if((int)stud[j] < (int)stud[nMin])	//(int) ��ζ�� ͨ��ѧ����������Ϊ(float)����ͨ���ɼ�����
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
	STUD stud[] = {{2001,"����",95.5f},{2009,"������",35.5f},{1005,"�Բ���",68},{2015,"������",35.1f}};
	Sort<STUD>(stud,COUNT(stud));
	Print<STUD>(stud,COUNT(stud));
	return 0;
}
