// test1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"

typedef struct Horse Horse;

struct Horse
{
	char test;
	int  age;
	int  height;
	char name[20];
	char father[20];
	char mother[20];
	Horse *next;
};

void main()
{
	Horse *first    = NULL;
	Horse *current  = NULL;
	Horse *previous = NULL;
	char test = '\0';
	
	for (;;)
	{
		printf("Do you want to enter details of a%s horse (Y or N)?\n",first !=NULL?"nother":"");
		scanf_s("%c",&test,sizeof(test));
		if (towlower(test) == 'n')
			break;

		//Allocate memory for a Horse structure
		current = (Horse*)malloc(sizeof(Horse));
		if (first == NULL)
			first = current;
		if (previous != NULL)
			previous->next = current;

		printf("Enter the name of the horse:\n");
		scanf_s("%s", current->name, sizeof(current->name));

		printf("How old is %s\n",current->name);
		scanf_s("%d", &current->age);

		printf("How high is %s (in hands)?\n",current ->name);
		scanf_s("%d", &current->height);

		printf("Who is %s's father?\n", current->name);
		scanf_s("%s", current->father, sizeof(current->father));

		printf("Who is %s's mother?\n", current->name);
		scanf_s("%s", current->mother, sizeof(current->mother));

		current->next = NULL;
		previous = current;
	}

	printf("\n");
	current = first;
	while (current!=NULL)
	{
		printf("%s is %d years old, %d hands high,",current->name, current->age,current->height);
		printf("and has %s and %s as parents.\n",current->father,current->mother);

		previous = current;
		current = current->next;
		free(previous);
		previous = NULL;
	}
	first = NULL;
}