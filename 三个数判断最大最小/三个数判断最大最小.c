#include<stdio.h>
#include <stdlib.h>
int main(void){
    double a,b,c;
    printf("请输入三个数:"); 
    scanf("%lf%lf%lf",&a,&b,&c);
/*找最大数*/ 
    if(a>b&&a>c)(printf("max=%.2lf\n",a));
    else if(b>a&&b>c)(printf("max=%.2lf\n",b));
    else printf("max=%.2lf\n",c);
/*找最小数*/ 
    if(a<b&&a<c)(printf("min=%.2lf\n",a));
    else if(b<a&&b<c)(printf("min=%.2lf\n",b));
    else printf("min=%.2lf\n",c);
	printf("                                              赵磊-南光科技出品\n");
    return 0;
    system("pause");
	
}