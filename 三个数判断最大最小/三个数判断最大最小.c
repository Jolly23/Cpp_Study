#include<stdio.h>
#include <stdlib.h>
int main(void){
    double a,b,c;
    printf("������������:"); 
    scanf("%lf%lf%lf",&a,&b,&c);
/*�������*/ 
    if(a>b&&a>c)(printf("max=%.2lf\n",a));
    else if(b>a&&b>c)(printf("max=%.2lf\n",b));
    else printf("max=%.2lf\n",c);
/*����С��*/ 
    if(a<b&&a<c)(printf("min=%.2lf\n",a));
    else if(b<a&&b<c)(printf("min=%.2lf\n",b));
    else printf("min=%.2lf\n",c);
	printf("                                              ����-�Ϲ�Ƽ���Ʒ\n");
    return 0;
    system("pause");
	
}