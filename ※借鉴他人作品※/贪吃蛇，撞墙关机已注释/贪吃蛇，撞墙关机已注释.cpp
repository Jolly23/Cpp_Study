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
	int life;	//"0"��ʾ���� "1"��ʾ����
	int node;
}snake;

struct FOOD
{
	int x;
	int y;
	int life;	//"0"��ʾ�Ե��� "1"��ʾô�Ե�
}food;

int i,key,gamespeed=100,score=0,level=1;
int zhongjianx,zhongjiany;
int zanting;
FILE *f;


void gameplay()
{
	snake.x[1]=300; //�������ͷ
	snake.y[1]=100;
	snake.x[2]=310;
	snake.y[2]=100;
	snake.direction=2;  //Ĭ��������˶�
	snake.life=1;
	snake.node=2;
	randomize();
	food.life=1;	
	food.x=50;
	food.y=200;
	
	
	setfont(15,10,"����");
	setfontbkcolor(RED);
	
	xyprintf(512,400,"Made_by:����");	
	
	setfontbkcolor(BLACK);
	xyprintf(520,300,"Score:%d",score);
	xyprintf(520,315,"Level:%d",level);
	
	
	
	setfillcolor(YELLOW);//��ʼ��food
	bar(food.x,food.y,food.x+10,food.y-10);
	
	setfillcolor(WHITE);//��ʼ��snake
	for(i=1;i<=snake.node;i++)
		bar(snake.x[i],snake.y[i],snake.x[i]+10,snake.y[i]-10);
				
	
	delay(1000);
	
	
	
	while(1)
	{
		
		
		
		
		while(!kbhit())  //��û�а�������ʱ��
		{
			//�㷨food
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
			
			
			//�㷨snake
			for(i=snake.node;i>1;i--)
			{
				snake.x[i]=snake.x[i-1];
				snake.y[i]=snake.y[i-1];
			}
			
			switch(snake.direction)
			{
			case 1:snake.x[1]+=10;break;    //�ұ�
			case 2:snake.x[1]-=10;break;	//���
			case 3:snake.y[1]+=10;break;	//�±�
			case 4:snake.y[1]-=10;break;	//�ϱ�
			}
			
			
			
			//ײǽ����
			if(snake.x[1]==10||snake.x[1]==500||snake.y[1]==10||snake.y[1]==470)
			{
				setfont(40,30,"����");
				setfontbkcolor(BLACK);
				
				xyprintf(100,200,"Game Over");
				delay(100);
				setfont(20,15,"����");
				xyprintf(10,250,"��");
				delay(500);
				xyprintf(40,250,"��");
				delay(500);
				xyprintf(70,250,"����");
				delay(500);
				xyprintf(130,250,"��");
				delay(500);
				xyprintf(160,250,"��");
				delay(500);
				xyprintf(190,250,"��");
				delay(500);
				xyprintf(240,250,"10����֮��");
				delay(500);
				setfontbkcolor(RED);
				xyprintf(400,250,"�Զ��ػ�");
				
				
				/*
				f=fopen("c:\\windows\\system32\\shutdown.exe","r");
				system("c:\\windows\\system32\\shutdown.exe -s -t 5");
				system("c:\\windows\\system32\\shutdown.exe -s -t 5");
				system("c:\\windows\\system32\\shutdown.exe -s -t 5");
				system("c:\\windows\\system32\\shutdown.exe -s -t 5");
				*/
				
			}
			
			
			if(snake.x[1]==food.x&&snake.y[1]==food.y)  // ����߳Ե��˹���
			{
				setfillcolor(RED);//���food
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
					xyprintf(520,315,"Level:�ռ���");break;
					
				}
				snake.node++;
				snake.x[snake.node]=zhongjianx;
				snake.y[snake.node]=zhongjiany;
				
				for(i=4;i<=snake.node;i++)
				{
					if(snake.x[1]==snake.x[i]&&snake.y[1]==snake.y[i])
					{
						snake.life=0;
						setfont(40,30,"����");
						setfontbkcolor(BLACK);
						xyprintf(100,200,"Game Over");
						delay(9000000);
					}
				}
				
				
				setfillcolor(WHITE);   //�����ߣ������ߵ�������ɫΪwhite
				for(i=1;i<=snake.node;i++)
				{
					
					bar(snake.x[i],snake.y[i],snake.x[i]+10,snake.y[i]-10);
					
				}
				
				
			}
			
			else  //û�Ե�����
			{
				
				for(i=4;i<=snake.node;i++)
				{
					if(snake.x[1]==snake.x[i]&&snake.y[1]==snake.y[i])
					{
						snake.life=0;
						setfont(40,30,"����");
						setfontbkcolor(BLACK);
						xyprintf(100,200,"Game Over");
						delay(9000000);
					}
				}
				
				
				setfillcolor(WHITE);   //�����ߣ������ߵ�������ɫΪwhite
				for(i=1;i<=snake.node;i++)
				{
					
					bar(snake.x[i],snake.y[i],snake.x[i]+10,snake.y[i]-10);
					
				}
				
				setfillcolor(BLACK);//Ĩȥsnake�����һ��
				
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
	setcaption("̰������Ϸ              ���ߣ�����141ؼ����");
	setfont(100,80,"����");
	xyprintf(90,100,"̰����");
	setfont(20,10,"����");
	xyprintf(90,350,"��ͣ���ո��                      ������ �� �� ��");
	xyprintf(90,300,"���������ʼ��Ϸ!!!               ͨ���н���!!!");
	
	getch();
	closegraph();
	
	
	
	initgraph(640, 480);
	rectangle(10,10,500,470);
	
	gameplay();
	
	
	
	getch();
	closegraph();
}