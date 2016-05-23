// SSTD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "STUD.h"

void main()
{
	STUD St;
	St.Load();
	while(1)	
		St.Menu();
}
