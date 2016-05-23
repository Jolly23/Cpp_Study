// CMap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Map.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	Stud a[] ={ {1001,"1ZhaoLei",95.5},{12301,"2Zh123oLei",95.5},
	{1021,"3sfLei",95.5},{1003,"7Zh43ei",95.5},
	{31,"4cvLei",95.5},{11,"8123Lei",95.5},
	{10345,"5rvLei",95.5},{14,"94Lei",95.5},
	{10342,"6awdLei",95.5},{13451,"10fsoLei",95.5} };
	CMap map(2);
	int i = 0;
	while(i < 10)
	{
		map.SetAt(a[i].nNumb,a[i]);
		i++;
	}
	Stud c = map[1001];
	VALUE ss = map[1111] = a[1];
	cout << ss.sName << endl;
	i = 0;
	while(i < 15)
	{
		map.LookUp(a[i].nNumb,c);
			cout << c.sName << endl;
		++i;
	}

	return 0;
}
