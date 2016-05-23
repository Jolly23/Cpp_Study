// HW1.cpp : Defines the entry point for the console application.
//
/*
模板函数练习：
a)使用冒泡排序或选择排序开发一个数组排序算法的模版函数；
b)在main函数中定义2-3个不同类型的数组代入排序函数后再打印；
c)打印数组也是一个独立的模板函数，例如：
template <class T>
void Print(T* pData,int n)//n代表数组元素个数
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

//template <class T>
void Print(int arr[],int n)//n代表数组元素个数
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
