/* 计算立方体体积 */

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

printf("按序输入物体的长、宽、高\n三个数字间以空格隔开:\n");

scanf("%f %f %f",&a,&b,&h);

  v=fun(a,b,h);       

  printf("v=%.2f\n",v);

  printf("                                              赵磊-南光科技出品\n");

}
