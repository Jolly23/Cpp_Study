#include "stdafx.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	int m;
	puts("«Î ‰»Î≥…º®£∫");
	scanf("%d",&m);
	int d=m/10;
	switch(d)
	{
				case(0):
				case(1):
				case(2):
				case(3):
				case(4):
				case(5):
					puts("Bad");
					break;
				case(6):
					puts("Just Pass");
					break;
				case(9):
				case(10):
					puts("Nice");
					break;
				default:
					puts("Error");
					
	}
	return 0;
}
