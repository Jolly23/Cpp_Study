/* ������������� */

#include<stdio.h>
#include <stdlib.h>       


float fun(float a,float b,float c)
{
float sum=a*b*c;
return sum;
}


void main()

{

float a,b,h,v;

printf("������������ĳ�������\n�������ּ��Կո����:\n");

scanf("%f %f %f",&a,&b,&h);

  v=fun(a,b,h);       

  printf("v=%.2f\n",v);

  printf("                                              ����-�Ϲ�Ƽ���Ʒ\n");

}
