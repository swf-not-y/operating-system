#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#define getpch(type) (type*)malloc(sizeof(type))
//
//struct jcb { // ������ҵ���ƿ�JCB
//	char name[10];
//	char state; //��ҵ״̬�����������У����
//	double super;  //���ȼ�
//	int atime;  //��ҵ����ʱ��
//	int ntime;  //��ҵ��Ҫ������ʱ��
//	double Ttime;   //��תʱ��
//	double Wtime;   //��Ȩ��תʱ��
//	struct jcb* link;   //������������
//}*ready = NULL, *p;    //readyΪ�������У�pΪ�������е���ҵ���¼ӵ���ҵ
//
//typedef struct jcb JCB;
//
//double finTime; //��¼ĳ��ҵ���ʱ��
//int nowtime = 0;
//double totalTtime = 0, totalWtime = 0; //����תʱ�䣬�ܴ�Ȩ��תʱ��
//int length = 0; //����ҵ��
//int cho;    //ѡ����ú����㷨
//
//void FCFS()  //���������ȷ�����
//{
//	JCB *first, *second;
//	int insert = 0;
//	if ((ready == NULL) || ((p->atime) < (ready->atime))) //��ҵ����,�������
//	{
//		p->link = ready;
//		ready = p;
//	}
//	else if (p->atime == ready->atime && p->ntime < ready->ntime)    //ͬʱ�����Ϊ����ҵ����
//	{
//		p->link = ready;
//		ready = p;
//	}
//	else // ��ҵ�Ƚϵ���ʱ��,�����ʵ���λ����
//	{
//		first = ready;
//		second = first->link;
//		while (second != NULL)
//		{
//			if ((p->atime) < (second->atime)) //��������ҵ�ȵ�ǰ��ҵ����ʱ��ǰ
//			{                               //���뵽��ǰ��ҵǰ��
//				p->link = second;
//				first->link = p;
//				second = NULL;
//				insert = 1;
//			}
//			else // ������ҵ�����ʱ������,����뵽��β
//			{
//				first = first->link;
//				second = second->link;
//			}
//		}
//		if (insert == 0) first->link = p;
//	}
//}
//
//void sort() //������Ӧ�ȶ����������ð������
//{
//	JCB *head;
//	head = getpch(JCB);
//	head->link = ready;
//	JCB *q, *prep, *temp, *tail;
//	tail = NULL;
//	while (head->link != tail)
//	{
//		prep = head;
//		q = head->link;
//		while (q->link != tail)
//		{
//			if (q->super < q->link->super)
//			{
//				temp = q->link;
//				prep->link = q->link;
//				q->link = q->link->link;
//				prep->link->link = q;
//				q = temp;
//			}
//			������
//			q = q->link;
//			prep = prep->link;
//		}
//		tail = q;
//	}
//	ready = head->link;
//	head->link = NULL;
//	free(head);
//}
//
//void HRRN() //������Ӧ�ȸ������Ⱥ���
//{
//	if (nowtime == 0)
//		FCFS(); //��û����ҵ�����ڴ�ʱ���������ȷ����㷨
//	else
//		sort(); //�Ѿ�����ҵ�����ڴ�󣬰�����Ӧ������
//}
//
//void input() // �������̿��ƿ麯��
//{
//	int i, num;
//	printf("\n ��������Ҫ��ӵ���ҵ������");
//	scanf("%d", &num);
//	length += num;
//	for (i = 0; i < num; i++)
//	{
//		printf("\n ��ҵ��No.%d:\n", i + 1);
//		p = getpch(JCB);    //����ռ�
//		printf("\n ������ҵ��:");
//		scanf("%s", p->name);
//		printf("\n��������ҵ����ʱ��:");
//		scanf("%d", &p->atime);
//		printf("\n ������ҵ��Ҫ������ʱ��:");
//		scanf("%d", &p->ntime);
//		printf("\n");
//		p->super = (nowtime - p->atime) / p->ntime + 1;
//		p->state = 'w';
//		p->link = NULL;
//		if (cho == 1)
//			FCFS(); // ���������ȷ�����
//		else
//			HRRN(); //���ø���Ӧ�����Ⱥ���
//	}
//}
//
//int space() //����ʣ����ҵ��
//{
//	int len = 0;
//	JCB* pr = ready;
//	while (pr != NULL)
//	{
//		len++;
//		pr = pr->link;
//	}
//	return(len);
//}
//
//void disp(JCB * pr) //����������ʾ����,������ʾ��������
//{
//	if (cho == 0)
//	{
//		printf("\n��ҵ��   ����ʱ��   ״̬   ��Ҫ��ʱ��\n");
//		printf(" %s", pr->name);
//		printf("         %d", pr->atime);
//		printf("         %c", pr->state);
//		printf("        %d", pr->ntime);
//		printf("\n");
//	}
//	else
//	{
//		printf("\n��ҵ��   ����ʱ��   ״̬   ��Ҫ��ʱ��   �ȴ�ʱ��   ��Ӧ��\n");
//		printf(" %s", pr->name);
//		printf("         %d", pr->atime);
//		printf("         %c", pr->state);
//		printf("        %d", pr->ntime);
//		printf("           %d", nowtime - pr->atime);
//		printf("        %.2f", pr->super);
//		printf("\n");
//	}
//}
//
//void destroy() //������ҵ��������(��ҵ���н���,������ҵ)
//{
//	printf("\n ��ҵ [%s] �����.\n", p->name);
//	free(p);
//}
//
//void running() // �����ڴ��е���ҵ
//{
//	finTime = nowtime; //���ʱ��
//	p->Ttime = finTime - p->atime; //��תʱ��
//	p->Wtime = p->Ttime / p->ntime; //��Ȩ��תʱ��
//	printf("\n��ҵ��  �ύʱ��  ��Ҫʱ��  ���ʱ��  ״̬  ��תʱ��  ��Ȩ��תʱ��\n");
//	printf("   %s       %d        %d        %.2f      %c     %.2f      %.2f\n", p->name, p->atime, p->ntime,
//		finTime, p->state, p->Ttime, p->Wtime);
//
//	totalTtime += p->Ttime;
//	totalWtime += p->Wtime;
//}
//
//void check() // ������ҵ�鿴����
//{
//	JCB *pr;
//	printf("\n **** ��ǰ�������е���ҵ��:%s", p->name); //��ʾ��ǰ���е���ҵ
//	running();
//	pr = ready;
//	if (cho == 1)    //����ø���Ӧ�������㷨��
//	{               //������ҵ���ʱҪ������Ӧ�������������������
//		while (pr != NULL)
//		{
//			if (nowtime < pr->atime)
//			{
//				pr = pr->link;
//				continue;
//			}
//			pr->super = ((nowtime - pr->atime) * 1.0) / pr->ntime + 1; //������Ӧ��
//			pr = pr->link;
//		}
//		HRRN(); //��������
//		pr = ready;
//	}
//	printf("\n ****��ǰ��������״̬Ϊ:\n"); //��ʾ��������״̬
//	while (pr != NULL)
//	{
//		if (nowtime < pr->atime)
//		{
//			pr = pr->link;
//			continue;
//		}
//		disp(pr);
//		pr = pr->link;
//	}
//	destroy();
//}
//
//int main() //������
//{
//	int len;
//	while (1)
//	{
//		printf("\t\t\t************************��ҵ�����㷨**************************\n\t\t\t");
//		printf("\t\t\t�����ȷ����㷨:0\n\t\t\t    \t\t\t ����Ӧ�������㷨:1\n");
//		printf("\t\t\t********************************************************\n\t\t\t");
//		printf("\t\t\t����������ѡ���Ӧ�ĵ����㷨: ");
//		scanf("%d", &cho);
//		printf("\n\t---------------------------------------------------------------\n");
//		if (cho == 0 || cho == 1)
//			break;
//		else
//		{

//			printf("\t\t\t�����������������!\n\n");
//			continue;
//		}
//	}
//	input();
//	len = space();
//	finTime = ready->atime;
//	while ((len != 0) && (ready != NULL))
//	{
//		getchar();
//		p = ready;
//		nowtime = p->ntime + finTime;
//		printf("\n\n���ڵ�ʱ����:%d \n", nowtime);
//		ready = p->link;
//		p->link = NULL;
//		p->state = 'R';
//		check();
//	}
//	if (cho == 0)
//	{
//		printf("\n ������ҵ�Ѿ����,�����ȷ����㷨ģ�����\n\n");
//	}
//	else
//	{
//		printf("\n ������ҵ�Ѿ����,����Ӧ�������㷨ģ�����\n\n");
//	}
//	printf("������ҵ��ƽ����תʱ��Ϊ��%.2f\n", totalTtime / length);
//	printf("������ҵ��ƽ����Ȩ��תʱ��Ϊ��%.2f\n", totalWtime / length);
//	getchar();
//	return 0;
//}
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
				else
				{
					mintime = jcb[k + 1].runtime;
					next = k;
					temp = jcb[k + 1];
					jcb[k + 1] = jcb[next];
					jcb[next] = temp;
				}
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
