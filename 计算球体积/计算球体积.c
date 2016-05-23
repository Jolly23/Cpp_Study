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

  printf("计算球体积\n输入r （r=圆半径）\n输入 r=");

  scanf("%f",&r);

  v=fun(r);

  printf("v=%f\n",v);

  printf("                                              赵磊-南光科技出品\n");


}
