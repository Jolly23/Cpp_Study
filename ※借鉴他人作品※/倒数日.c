#include"stdio.h"
int year,month,day,year1,month1,day1,result,n,i,x,y;
int table[]={29,31,28,31,30,31,30,31,31,30,31,30,31};     //����ÿ���µ�����
int table1[] = {28,31,29,31,30,31,30,31,31,30,31,30,31};
main()
{
	printf("��������ʼ���ں���ֹ����\n  ��ʽ��yyyy mm dd yyyy mm dd\n");
	scanf("%d %d %d %d %d %d",&year,&month,&day,&year1,&month1,&day1);            //���뺯��

	if(year*100+month*10+day>year1*100+month1*10+day1||year<1||year1<1||
	    month<1||month>12||month1<1||month1>12||
		day<1||day1<1||
		day>table1[month]||day1>table1[month1])      //��������Ƿ���ȷ
		printf("��ʽ����ȷ��"); 
	
	else if(year%4!=0 && month==2 && day>28)   
		printf("��ʽ����ȷ��"); 
	else if(year1%4!=0 && month1==2 && day1>28)   
		printf("��ʽ����ȷ��");                     //���ڷ�����2�µļ��
	else
	{
		x = month;
		y = year;
		if(year==year1)   //while they are in the same year!
		{
			if(month==month1)   // and the same month!
				result = day1-day;  //   so....
			else    //the same year but different  monthes.
			{
				if(year%4==0 && month==2)  
					result = table[0]-day;  
				else
					result = table[month]-day;    //Ӣ�ﲻ���������Ƚ���ʼ�����ʼ��ʣ�����������
				for(month++;month<month1;month++)
				{
					if(year%4==0 && month==2)
						result = result + table[0];  
					else
						result = result+table[month];     //�����µ�������������
				}
				result = result+day1;     //���һ���°���������������@��
				}
		}
		else          //when they are in different years.   similar to����ġ�
		{
			if(year%4==0 && month==2)
				result = table[0]-day;
			else
				result = table[month]-day;
			for(month++;month<=12;month++)
				if(year%4==0 && month==2)
					result = result + table[0];
				else
					result = result + table[month];
			for(year++;year<year1;year++)
			{	
				if(year%4==0)
					result = result + 366;
				else
					result = result + 365;

			}
			for(i=1;i<month1;i++)
				result = result + table[i];
			result = result + day1;
		}
		printf("%d��%d��%d�յ�%d��%d��%d��\n����%d��\n",year,x,day,year1,month1,day1,result);     //������
	}

	for(i=0;i<5;i++) printf("\n");
}