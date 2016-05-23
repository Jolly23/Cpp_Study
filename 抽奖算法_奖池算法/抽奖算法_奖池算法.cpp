// ≥ÈΩ±À„∑®_Ω±≥ÿÀ„∑®.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "User.h"
#include <conio.h>
#include <iostream>
using namespace std;

CUser User;
void Menu();

void main()
{
	User.Default();

	do{
		system("cls");
		Menu();
	} while(true);
}

void Menu()
{
	fflush;
	char cSel;
	cout << "1.µ«¬º" << endl
		 << "2.◊¢≤·" << endl;
	cSel = getch();
	switch(cSel)
	{
	case '1':
		User.Login() ;
	case '2':
		User.Signup();
	}
}