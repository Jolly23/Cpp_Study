// NewDelete.cpp : Defines the entry point for the console application.
//



// New & Delete 代替malloc、free写法练习



#include "stdafx.h"
#include <iostream>

int main(int argc, char* argv[])
{
	int *p = new int ;
	int a= 7;
	int b= 13;

	*p = a;
	a  = b;
	b  = *p;

	std::cout << " a = " << a << std::endl;
	std::cout << " b = " << b << std::endl;

	std::cout << "输入一个大于0的数字：" << std::endl;
	std::cin  >> *p;

	int i = 0;
	int *c = new int[*p];
	while(i<*p)
	{
		c[i] = i*89-5295+4189/58*66+99999;
		i++;
	}
	i = 0;
	while(i<*p)
	{
		std::cout << "c[" << i+1 << "] = " << c[i] << std::endl;
		++i;
	}
	delete []p;
	return 0;
}
