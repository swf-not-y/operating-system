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

int n=0;	//��¼�������
int m = 0;   //��¼����ִ�в�����
struct Jincheng a[20],*p = a;
int time;     //ʱ��Ƭ��С
int b[20];  //�洢����õ��������ȼ�

// ��ӽ���
void Add(struct Jincheng a[])
{   int i;
	char decide;

	for(i=0;i<20;i++)
	{
	printf("�������������");
	scanf("%s",a[i].name);

	printf("��������̵����ȼ���");
	scanf("%d",&a[i].yxj);

	printf("�����������Ҫ��ʱ�䣺");
	scanf("%d",&a[i].needtime);

	a[i].arrivetime = i;
	a[i].usedtime = 0;
	a[i].state ='W';
	n = n + 1;

	printf("��Ҫ�������ӽ������ǣ�Y������N����");
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

//��������
void Process(struct Jincheng a[])
{
	int i,w,max = -999;

//��������ȼ�
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
	
		

	//ִ��������ȼ�������
		
	

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






//��ӡ����ִ���б�
void Print()    
{
	printf("\n");
	int j;
	printf("������	���ȼ�	����ʱ��  ��Ҫʱ��  ����ʱ��  ����״̬\n");
	for(j=0;j<n;j++)
		{
	printf("  %s    %-6d  %-8d  %-8d  %-8d  %-8c    \n",a[j].name,a[j].yxj,a[j].arrivetime,a[j].needtime,a[j].usedtime,a[j].state);
		}
	printf("\n");
	



}




void main()
{	
	int i;
	
	printf("����ʱ��Ƭ�Ĵ�С��");
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


