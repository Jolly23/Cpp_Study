/* 计算圆面积的程序 */

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

  printf("将会计算圆面积\n输入r （r=圆半径）\n输入 r=");

  scanf("%f",&r);

  s=fun(r);

  printf("s=%.2f\n",s);

  printf("                                              赵磊-南光科技出品\n");

}

