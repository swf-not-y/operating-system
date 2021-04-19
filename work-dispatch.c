#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define getpch(type) (type*)malloc(sizeof(type))
#define N 25
void input1(int);
void FCFS(int);//�����ȷ���   
void HRP(int);//��Ӧ�ȸߵ�����
void SJF(int);//����ҵ����
//void quit();
int num, i, j, k, m, n;
struct JCB{                   //����һ���ṹ��
	char name[10];            //��ҵ��
	float arrivetime;         //��ҵ�ύʱ��  
	float runtime;            //��ҵ����ʱ��  
	float starttime;                //��ʼʱ��       
	float finishtime;             //���ʱ��       
	float T;                  //��תʱ��       
	float W;                  //��Ȩ��תʱ��  
}jcb[N], temp;



int Menu()
{
	int choic;
	printf("1.�����ȷ���FCFS�������㷨\n");
	printf("2.����ҵ���� (SJF) �����㷨\n");
	printf("3.��Ӧ�ȸ�������(HRRN)�����㷨\n");
	printf("4.�˳�ϵͳ\n");
	printf("��ѡ��˵���(1-4):");
	while(!scanf("%d", &choic))//choic--�˵�������
	{
		getchar();
		printf("\n�������!!!!!!����������\n");

	}
	return choic;
}
void main()
{
	int choic, n = 1;
	input1(n);
	while (1)
	{
		choic = Menu();
		switch (choic)
		{
		case 1:
			FCFS(n); //�����ȷ�������㷨
			break;
		case 2:
			SJF(n); //����ҵ���ȵ����㷨
			break;
		case 3:
			HRP(n); //��Ӧ�ȸ������ȵ����㷨
			break;
		case 4:
			//quit();
			break;
		}
	}
}
void input1() // ������ҵ���ƿ麯�� 
{
	int i=0;
	//j = 0;
	printf("��������ҵ������");
	while (!scanf("%d", &num))//��������е����ݲ���ʶ��Ϊ�����������������ݲ��㣬scanf����0,0��ִ��while
	{
		getchar();
		printf("�������------->����������\n");
		printf("\n");
		printf("��������ҵ����:");
	}

	printf("\n");
	for (i = 0; i<num; i++){
		printf("\t��%d����ҵ��:", i + 1);
		scanf("%s", &jcb[i].name);
		printf("\t��������ҵ�ύʱ��:");
		scanf("%f", &jcb[i].arrivetime);
		printf("\t��������ҵ����ʱ��:");
		scanf("%f", &jcb[i].runtime);
		printf("\n");
	}
}


//void quit()
//{
//	printf("ллʹ�ø�ϵͳ!\n");
//	exit(0);
//}

void output()
{
	float numT = 0, numW = 0, avgT = 0, avgW = 0;
	printf("-----------------------------------------------------------------------\n");
	printf(" ��ҵ��  �ύʱ��  ����ʱ��  ��ʼʱ��  ���ʱ��  ��תʱ��  ��Ȩ��תʱ��\n");
	for (i = 0; i<num; i++)
	{
		printf("   %-8s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f", jcb[i].name, jcb[i].arrivetime, jcb[i].runtime, jcb[i].starttime, jcb[i].finishtime, jcb[i].T, jcb[i].W);
		printf("\n");
		numT = numT + jcb[i].T;
		numW = numW + jcb[i].W;
	}
	printf("-----------------------------------------------------------------------\n");
	avgT = numT / num;//ƽ����תʱ��
	avgW = numW / num;//ƽ����תϵ��
	printf("ƽ����ҵ��תʱ�䣺%.2f\n", avgT);
	printf("\n");
	printf("ƽ����Ȩ��ҵ��תʱ�䣺%.2f\n", avgW);
	printf("\n");
}
void sort()
{
	int i, j;
	for (j = 0; j<num; j++)//ð�ݷ�����,�Ե���ʱ���С��������
	{
		for (i = 0; i<num - j - 1; i++)
		{
			if (jcb[i].arrivetime>jcb[i + 1].arrivetime)
			{
				temp = jcb[i];
				jcb[i] = jcb[i + 1];
				jcb[i + 1] = temp;
			}
		}
	}
}
void running()
{
	for (k = 0; k<num; k++)//k�������������
	{
		if (k == 0)//���е�һ����ҵ
		{
			jcb[k].starttime = jcb[k].arrivetime;
			jcb[k].finishtime = jcb[k].arrivetime + jcb[k].runtime;
		}
		else
		{
			if (jcb[k].arrivetime >= jcb[k - 1].finishtime)//��ǰ��ҵ�Ѿ���������һ����ҵ��û�е�����߸պõ���
			{
				jcb[k].starttime = jcb[k].arrivetime;
				jcb[k].finishtime = jcb[k].arrivetime + jcb[k].runtime;
			}
			else//��ǰ��ҵδ��ɣ���һ����ҵ�ѵ���
			{
				jcb[k].starttime = jcb[k - 1].finishtime;
				jcb[k].finishtime = jcb[k - 1].finishtime + jcb[k].runtime;
			}
		}

	}
	for (k = 0; k<num; k++)
	{
		jcb[k].T = jcb[k].finishtime - jcb[k].arrivetime;
		jcb[k].W = jcb[k].T / jcb[k].runtime;//��תʱ��/ִ��ʱ��
	}
}
void FCFS()//�����ȷ���
{
	sort();
	running();
	output();//�����ҵ���ȱ�
}
void SJF()//����ҵ����
{
	int next = 0;
	float mintime;//��ҵ���е���Сʱ��
	sort();
	for (m = 0; m<num; m++)
	{
		i = 0;
		if (m == 0)
		{
			jcb[m].finishtime = jcb[m].arrivetime + jcb[m].runtime;
		}
		else
		{
			jcb[m].finishtime = jcb[m - 1].finishtime + jcb[m].runtime;
		}
		for (n = m + 1; n<num; n++)
		{
			if (jcb[n].arrivetime <= jcb[m].finishtime){//�ж���ÿ����ҵ���֮�����ж�����ҵ����     
				i++;
			}
			mintime = jcb[m + 1].runtime;
			next = m + 1;
			for (k = m + 1; k<i; k++)//�ҳ����浽�����ҵ������ʱ����С��
			{
				if (jcb[k + 1].runtime<mintime)
				{
					mintime = jcb[k + 1].runtime;
					next = k + 1;
					temp = jcb[m + 1];//������������ʱ��
					jcb[m + 1] = jcb[next];
					jcb[next] = temp;
				}
				//else
				//{
				//	mintime = jcb[k + 1].runtime;
				//	next = k;
				//	temp = jcb[k + 1];
				//	jcb[k + 1] = jcb[next];
				//	jcb[next] = temp;
				//}
			}
		}
		running();
		output();
	}
}

void HRP()//�����Ӧ������*local function definitions are illegal,�ֲ����������ǲ��Ϸ��ģ�
{
	int flag;
	float max;//������Ӧ��  
	sort();
	for (m = 0; m<num; m++)
	{
		i = 0;
		if (m == 0)
		{
			jcb[m].finishtime = jcb[m].arrivetime + jcb[m].runtime;
		}
		else
		{
			jcb[m].finishtime = jcb[m - 1].finishtime + jcb[m].runtime;
		}
		for (n = m + 1; n<num; n++)
		{
			if (jcb[n].arrivetime <= jcb[m].finishtime)
				i++;
		}
		max = (jcb[m].finishtime - jcb[m + 1].arrivetime) / jcb[m + 1].runtime;//��Ӧ��   
		flag = m + 1;
		for (k = m + 1; k<i; k++)
		{
			if (max <= (jcb[k].finishtime - jcb[k + 1].arrivetime) / jcb[k + 1].runtime)//��Ӧ�ȴ����ִ��
			{
				max = (jcb[k].finishtime - jcb[k + 1].arrivetime) / jcb[k + 1].runtime;
				flag = k + 1;
				temp = jcb[k];
				jcb[k] = jcb[flag];
				jcb[flag] = temp;
			}
		}
	}
	running();
	output();

}
