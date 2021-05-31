#include<stdio.h>
void Add(struct Jincheng a[]);
void Process(struct Jincheng a[]);
void Print();    

struct Jincheng
{
	char name[5];
	int yxj;
	int arrivetime;
	int needtime;
	int usedtime;
	char state;
};

int n=0;	//记录任务个数
int m = 0;   //记录任务执行步骤数
struct Jincheng a[20],*p = a;
int time;     //时间片大小
int b[20];  //存储保存好的有序优先级

// 添加进程
void Add(struct Jincheng a[])
{   int i;
	char decide;

	for(i=0;i<20;i++)
	{
	printf("请输入进程名：");
	scanf("%s",a[i].name);

	printf("请输入进程的优先级：");
	scanf("%d",&a[i].yxj);

	printf("请输入进程需要的时间：");
	scanf("%d",&a[i].needtime);

	a[i].arrivetime = i;
	a[i].usedtime = 0;
	a[i].state ='W';
	n = n + 1;

	printf("还要继续增加进程吗？是（Y），否（N）：");
	scanf("%s",&decide);
	printf("\n");

	if(decide == 'y' || decide =='Y')
	{continue;

	}

	else
	{	
		break;
	}

	}

}

//处理任务
void Process(struct Jincheng a[])
{
	int i,w,max = -999;

//找最大优先级
	while(m!=0)
	{   

	
		for(i=0;i<n;i++)
		{  
			if(a[i].state !='F')

				if(max < a[i].yxj)
				{
					max = a[i].yxj;
					w = i;
				}

		     	else
				     continue;


			else
				continue;
			
		}
	
		

	//执行最大优先级的任务
		
	

			a[w].state = 'R';
			a[w].yxj = a[w].yxj - 1;
			a[w].usedtime = a[w].usedtime + time;
			Print();


			if(a[w].usedtime == a[w].needtime)
			{	a[w].state = 'F';
			a[w].yxj = -1000;}
			else
				a[w].state = 'W';
		
	   	m = m-1;
	
		max = -999;
	}
	

}






//打印进程执行列表
void Print()    
{
	printf("\n");
	int j;
	printf("进程名	优先级	到达时间  需要时间  已用时间  进程状态\n");
	for(j=0;j<n;j++)
		{
	printf("  %s    %-6d  %-8d  %-8d  %-8d  %-8c    \n",a[j].name,a[j].yxj,a[j].arrivetime,a[j].needtime,a[j].usedtime,a[j].state);
		}
	printf("\n");
	



}




void main()
{	
	int i;
	
	printf("设置时间片的大小：");
	scanf("%d",&time);
	printf("\n");
	Add(p);

	for(i=0;i<n;i++)
	{
		m = a[i].needtime + m;
	}
	if(m%time!=0)
		m = m/time + 1;
	else
		m = m/time;

	Print();
	Process(p);
	Print();


}


