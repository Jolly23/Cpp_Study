#include<stdio.h>
#include <stdlib.h>
#define PI 3.141592


float fun(float r)
{
float sum=r*r*r*PI*4/3;
return sum;
}


void main()

{ 

  float r,v;

  printf("���������\n����r ��r=Բ�뾶��\n���� r=");

  scanf("%f",&r);

  v=fun(r);

  printf("v=%f\n",v);

  printf("                                              ����-�Ϲ�Ƽ���Ʒ\n");


}
