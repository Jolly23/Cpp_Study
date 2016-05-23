#include "graphics.h"
#include <stdio.h>
#define N 200
#define BLACK 0
#define YELLOW 0xFCFC54
#define LIGHTGREEN 0x54FC54	
#define RED 0xA80000
#define WHITE 0xFCFCFC
#define LEFT 293
#define RIGHT 295
#define UP 294
#define DOWN 296
#define KONGGE 48



struct SNAKE
{
	int x[N];
	int y[N];
	int direction;
	int life;	//"0"表示死亡 "1"表示活着
	int node;
}snake;

struct FOOD
{
	int x;
	int y;
	int life;	//"0"表示吃掉了 "1"表示么吃掉
}food;

int i,key,gamespeed=100,score=0,level=1;
int zhongjianx,zhongjiany;
int zanting;
FILE *f;


void gameplay()
{
	snake.x[1]=300; //这个是蛇头
	snake.y[1]=100;
	snake.x[2]=310;
	snake.y[2]=100;
	snake.direction=2;  //默认向左边运动
	snake.life=1;
	snake.node=2;
	randomize();
	food.life=1;	
	food.x=50;
	food.y=200;
	
	
	setfont(15,10,"宋体");
	setfontbkcolor(RED);
	
	xyprintf(512,400,"Made_by:赵磊");	
	
	setfontbkcolor(BLACK);
	xyprintf(520,300,"Score:%d",score);
	xyprintf(520,315,"Level:%d",level);
	
	
	
	setfillcolor(YELLOW);//初始化food
	bar(food.x,food.y,food.x+10,food.y-10);
	
	setfillcolor(WHITE);//初始化snake
	for(i=1;i<=snake.node;i++)
		bar(snake.x[i],snake.y[i],snake.x[i]+10,snake.y[i]-10);
				
	
	delay(1000);
	
	
	
	while(1)
	{
		
		
		
		
		while(!kbhit())  //当没有按键按下时候
		{
			//算法food
			if(food.life==0)
			{
				food.x=rand()%400+90;
				food.y=rand()%400+40;
				while(food.x%10!=0)
					food.x++;
				while(food.y%10!=0)
					food.y++;
				food.life=1;
			}
			
			if(food.life==1)
			{
				setfillcolor(YELLOW);
				bar(food.x,food.y,food.x+10,food.y-10);
			}
			
			
			
			
			
			
			zhongjianx=snake.x[snake.node];
			zhongjiany=snake.y[snake.node];
			
			
			//算法snake
			for(i=snake.node;i>1;i--)
			{
				snake.x[i]=snake.x[i-1];
				snake.y[i]=snake.y[i-1];
			}
			
			switch(snake.direction)
			{
			case 1:snake.x[1]+=10;break;    //右边
			case 2:snake.x[1]-=10;break;	//左边
			case 3:snake.y[1]+=10;break;	//下边
			case 4:snake.y[1]-=10;break;	//上边
			}
			
			
			
			//撞墙死亡
			if(snake.x[1]==10||snake.x[1]==500||snake.y[1]==10||snake.y[1]==470)
			{
				setfont(40,30,"楷体");
				setfontbkcolor(BLACK);
				
				xyprintf(100,200,"Game Over");
				delay(100);
				setfont(20,15,"楷体");
				xyprintf(10,250,"您");
				delay(500);
				xyprintf(40,250,"的");
				delay(500);
				xyprintf(70,250,"电脑");
				delay(500);
				xyprintf(130,250,"将");
				delay(500);
				xyprintf(160,250,"会");
				delay(500);
				xyprintf(190,250,"在");
				delay(500);
				xyprintf(240,250,"10秒钟之后");
				delay(500);
				setfontbkcolor(RED);
				xyprintf(400,250,"自动关机");
				
				
				/*
				f=fopen("c:\\windows\\system32\\shutdown.exe","r");
				system("c:\\windows\\system32\\shutdown.exe -s -t 5");
				system("c:\\windows\\system32\\shutdown.exe -s -t 5");
				system("c:\\windows\\system32\\shutdown.exe -s -t 5");
				system("c:\\windows\\system32\\shutdown.exe -s -t 5");
				*/
				
			}
			
			
			if(snake.x[1]==food.x&&snake.y[1]==food.y)  // 如果蛇吃到了果子
			{
				setfillcolor(RED);//清除food
				bar(food.x,food.y,food.x+10,food.y-10);
				food.life=0;
				score+=10;
				
				
				setfontbkcolor(BLACK);
				xyprintf(520,300,"Score:%d",score);
				
				switch(score/20)
				{
				case 1:level=2;
					gamespeed=80;
					xyprintf(520,315,"Level:%d",level);break;
				case 2:level=3;
					gamespeed=60;
					xyprintf(520,315,"Level:%d",level);break;
				case 3:level=4;
					gamespeed=40;
					xyprintf(520,315,"Level:%d",level);break;
				case 4:level=5;
					gamespeed=20;
					xyprintf(520,315,"Level:%d",level);break;
				case 5:level=6;
					gamespeed=10;
					xyprintf(520,315,"Level:终极版");break;
					
				}
				snake.node++;
				snake.x[snake.node]=zhongjianx;
				snake.y[snake.node]=zhongjiany;
				
				for(i=4;i<=snake.node;i++)
				{
					if(snake.x[1]==snake.x[i]&&snake.y[1]==snake.y[i])
					{
						snake.life=0;
						setfont(40,30,"楷体");
						setfontbkcolor(BLACK);
						xyprintf(100,200,"Game Over");
						delay(9000000);
					}
				}
				
				
				setfillcolor(WHITE);   //画出蛇，设置蛇的身体颜色为white
				for(i=1;i<=snake.node;i++)
				{
					
					bar(snake.x[i],snake.y[i],snake.x[i]+10,snake.y[i]-10);
					
				}
				
				
			}
			
			else  //没吃到果子
			{
				
				for(i=4;i<=snake.node;i++)
				{
					if(snake.x[1]==snake.x[i]&&snake.y[1]==snake.y[i])
					{
						snake.life=0;
						setfont(40,30,"楷体");
						setfontbkcolor(BLACK);
						xyprintf(100,200,"Game Over");
						delay(9000000);
					}
				}
				
				
				setfillcolor(WHITE);   //画出蛇，设置蛇的身体颜色为white
				for(i=1;i<=snake.node;i++)
				{
					
					bar(snake.x[i],snake.y[i],snake.x[i]+10,snake.y[i]-10);
					
				}
				
				setfillcolor(BLACK);//抹去snake的最后一节
				
				bar(zhongjianx,zhongjiany,zhongjianx+10,zhongjiany-10);
				
				
			}
			
			
			
			
			rectangle(10,10,500,470);
			
			
			
			
			
			delay(gamespeed);
			
		}
		
		if(kbhit())
		{
			key=getch();
			if(key==LEFT && snake.direction!=1)
				snake.direction=2;
			if(key==RIGHT && snake.direction!=2)
				snake.direction=1;
			if(key==UP && snake.direction!=3)
				snake.direction=4;
			if(key==DOWN && snake.direction!=4)
				snake.direction=3;
			if(key==' ')
			{
				key=43;
				while(1)
				{	
					while(!kbhit())	
						delay(50);
					
					if(kbhit())
						zanting=getch();
					
					if(zanting==' ')
						break;
				}				
			}
			
		}
	}
	
}






void main()
{
	
	initgraph(640, 480);
	setcaption("贪吃蛇游戏              作者；电子141丶赵磊");
	setfont(100,80,"宋体");
	xyprintf(90,100,"贪吃蛇");
	setfont(20,10,"宋体");
	xyprintf(90,350,"暂停：空格键                      方向：上 下 左 右");
	xyprintf(90,300,"按任意键开始游戏!!!               通关有奖励!!!");
	
	getch();
	closegraph();
	
	
	
	initgraph(640, 480);
	rectangle(10,10,500,470);
	
	gameplay();
	
	
	
	getch();
	closegraph();
}