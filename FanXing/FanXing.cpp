// FanXing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T>
T max(T n1, T n2)
{
	return n1 > n2 ? n1 : n2 ;
}

void main()
{
	max<double>(1.6,9.5);
}
