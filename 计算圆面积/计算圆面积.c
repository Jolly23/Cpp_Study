/* ����Բ����ĳ��� */

#include<stdio.h>
#include <stdlib.h>
#define PI 3.141592

float fun(float r)
{
float sum=PI*r*r;
return sum;
}

void main()

{ 

  float r,s;

  printf("�������Բ���\n����r ��r=Բ�뾶��\n���� r=");

  scanf("%f",&r);

  s=fun(r);

  printf("s=%.2f\n",s);

  printf("                                              ����-�Ϲ�Ƽ���Ʒ\n");

}

