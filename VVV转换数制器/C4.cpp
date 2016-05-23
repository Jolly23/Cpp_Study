/*


升级日志：

  
2015/3/29：重大更新，建立循环支持多次执行，并设置退出选项，优化菜单结构

	2015/3/27：	优化模式选择，不需要输入模式数字后再按回车，直接进入模式；	
	
		2015/3/25:	去掉二进制输出时前面带的无效位的0，优化运行速度，使用循环解决二进制结果；
					增加输出八进制模式3；
	  
			2015/3/24:	重新修订变量名称；
		
				2015/3/21：	发布；
		  
																		作者：电子141-赵磊
			
			  
*/

#include "stdafx.h"
#include <stdio.h>
#include <math.h>//pow函数头文件，计算次幂
#include <conio.h>//getch的头文件，防止程序一闪就退出
#include <process.h>//system头文件，支持清屏("cls")与暂停("pause")


int main(int argc, char* argv[])
{
	int mode;
	
	do{
		
		system("cls");
			
//模式选择
		puts("********************");
		puts("请选择模式：");
		puts("1、十进制转二进制");
		puts("2、十进制转十六进制");
		puts("3、十进制转八进制");
		puts("0、退出程序");	
		puts("********************");
		printf("请输入模式对应的数字：");
		
		
		
		mode=getch();
		
		
		
		//模式1：十进制转二进制
		if(mode=='1')
			
		{

			printf(" \n\n输入一个十进制数字：");
			int a;
			scanf("%d",&a);
			
			printf("\n\n此数字对应的二进制数是：");
			
			int nRes[16];//把位转换后的二进制数录入数组，准备去除前面无实际意义数位的 0
			int n;
			
			int bl=0;
			while(bl<=15)
			{
				n=(int)pow(2,15-bl);
				nRes[bl]=a/n%2;
				bl++;
			}//录入数组完毕
			
			
			int Search=0;
			while(nRes[Search]==0)	
			{	
				Search++;
			}//排查前面无效位的 0， 直到遇到 1
			
			
			
			while(Search<=15)//从有效位开始打印二进制数
			{
				printf("%d",nRes[Search]);
				Search++;
			}

			printf("\n\n\n此程序仅可以转换十进制的整数，\n带小数的数字暂未支持。\n\n");
			
		}
		
		
		
		//模式2：十进制转十六进制
		if(mode=='2')
		{

			printf(" \n\n输入一个十进制数字：");
			int a;
			scanf("%d",&a);
			printf("\n此数字对应的十六进制数是：%X\n\n",a);//直接转系统转化为Hex输出
			
		}
		
		
		//模式1：十进制转八进制
		if(mode=='3')
		{

			printf(" \n\n输入一个十进制数字：");
			int a;
			scanf("%d",&a);
			printf("\n此数字对应的八进制数是：%o\n\n",a);//直接转系统转化为o输出
		}
		
		
		//模式选择错误
		if(mode!='1' && mode!='2')
			if(mode!='3')
				if(mode!='0')
					printf("\n\n您的输入有误！\n\n");
		if(mode!='0')	system("pause");
	}while(mode!='0');
	
	
	
	
	//商标
	printf("\n\n\n\n\n赵磊-天津科技出品\n");
	
	printf("\n\n\n亲爱的闫霄小同学，按任意键退出哦~     么\n");
	
	printf("\n\n\t\t");

	system("pause");
	
	/*
	char UselessNumber;//防止程序自动闪退
	getch();
	*/
	return 0;
}
