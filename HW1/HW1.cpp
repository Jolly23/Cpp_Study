// HW1.cpp : Defines the entry point for the console application.
//
/*
ģ�庯����ϰ��
a)ʹ��ð�������ѡ�����򿪷�һ�����������㷨��ģ�溯����
b)��main�����ж���2-3����ͬ���͵�����������������ٴ�ӡ��
c)��ӡ����Ҳ��һ��������ģ�庯�������磺
template <class T>
void Print(T* pData,int n)//n��������Ԫ�ظ���
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

//template <class T>
void Print(int arr[],int n)//n��������Ԫ�ظ���
{
	int i = 0, j = 0;

	while(i < n)
	{
		j = 0;
		while(j < n-i)
		{
			if(arr[i] > arr[j])
			{
				int t = arr[i];
				arr[i]= arr[j];
				arr[j]= t;
			}
			++j;
		}
		++i;
	}

	i = 0;
	while(i < n)
		cout << arr[i++] << endl;
}


int main(int argc, char* argv[])
{
	int arr[] = 
	{56,58,156,184,8494,4694,54164,1,584,0,41564,-45,-56368,89441536,5641,21691,65416584,165416,12316851,165465};
	Print(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
