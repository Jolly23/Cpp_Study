// algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int NS(int i , int  j)
{
	return i < j;
}

void main()
{
	int arr[] = {486,416,16,489,546,489,15,84,96,1};
	vector<int> v_data;
	for(int i = 0; i < 10; ++i)
		v_data.push_back(arr[i]);

	sort(v_data.begin(), v_data.end(), NS);
	for(int j = 0; j < 10; ++j)
		cout << v_data[j] << endl;
}
