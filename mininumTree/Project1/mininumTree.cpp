#include<stdio.h>
#include<malloc.h>
#include<time.h>       //�����������Ҫ
#include<stdlib.h>
#include<omp.h>
#include<iostream>
#define INFINITY 65535 //�ڵ㲻�ɴ�
#define N 6   //ͼ�Ľڵ����

void initGraph();
int createMininumTree();
int* getMininumArray(int, int[]);


//�����ڽӾ������ʽ�洢ͼ
int graph[N][N];
int c[N];       //��С�������Ľڵ㼯��
int t[N];       //ʣ��û�м�����С�������Ľڵ�
int mininumTreeIndex[N - 1][3];   //��С��������·��������1,2,3�зֱ�����ϵ�����С��С�Ȩֵ��

/** ʹ��prime�㷨����С�����������п�����߳����Ч�ʣ��������ԣ�
�����ڼ�����СȨֵʱ��ͬʱ��c�и��ڵ㵽t�нڵ�ĸ�����Сֵ��Ȼ��Ƚϡ�
**/

int main()
{
	int i = 0, j = 0;
	int coreNum = opm_get_num_procs();  //��ô������ĸ���
	printf("����������%d\n", coreNum);
#pragma omp parallel for
	for (i = 1; i < 11; i++)
		printf("%d\t", i);


	/*initGraph();
	if (createMininumTree())
	{
	printf("��С�������ṹ��\n");
	for (; i<N - 1; i++)
	{

	printf("����%-4d������%-4dȨֵ%-10d", mininumTreeIndex[i][0], mininumTreeIndex[i][1], mininumTreeIndex[i][2]);
	printf("\n");
	}
	}
	else
	{
	printf("�޷�������С������\n");
	}*/
	return 0;
}
/*
������С������,����0����������С������
���������С������
*/
int createMininumTree()
{
	int visitedCount = 1;          //�Ѿ���ӵ�����c�еĽڵ�����
	int i = 0, j = 0, k = 0;
	int minValue = INFINITY, minRow, minCol;
	int *minArrayPointer;          //��������ָ��
	int flag = 0;                    //�Ƿ��ܹ�������С�������ı��
	c[0] = 0;                        //����һ���ڵ����c�У�ͬʱ��t��ɾ��
	t[0] = -1;

	//һ�����һ���ڵ㵽c��ͬʱ��v��ɾ��һ���ڵ�
	for (i = 0; i<N; i++)
	{
		flag = 0;
		minValue = INFINITY;
		minRow = INFINITY;
		minCol = INFINITY;
		/**
		�õ���c��tȨֵ��Сֵ
		**/
		for (j = 0; j<visitedCount; j++)
		{
			minArrayPointer = getMininumArray(c[j], t);
			if (*(minArrayPointer + 2)<minValue)
			{
				minRow = *(minArrayPointer);
				minCol = *(minArrayPointer + 1);
				minValue = *(minArrayPointer + 2);
				flag = 1;
			}
		}
		/**
		��ͼ�й�����ͨͼ
		*/
		if (flag == 0)
			break;
		else
		{
			mininumTreeIndex[visitedCount - 1][0] = minRow;
			mininumTreeIndex[visitedCount - 1][1] = minCol;
			mininumTreeIndex[visitedCount - 1][2] = minValue;
			c[visitedCount++] = minCol;
			t[minCol] = -1;


		}

	}


	if (visitedCount == N)
		return 1;
	else
		return 0;
}

/**
�õ��ڵ�i��Ϊ���ʽڵ㼯��t�е���СȨֵ���С��С�ֵ,������Խ��в������
**/
int* getMininumArray(int i, int unVisited[N])
{
	int minArray[3];
	int minCol = INFINITY, minRow = INFINITY, minValue = INFINITY;
	int j, *minPointer;

	for (j = 0; j<N; j++)
	{
		if (unVisited[j] == -1)
			continue;
		if (graph[i][j]<minValue)
		{
			minRow = i;
			minCol = j;
			minValue = graph[i][j];
		}
	}
	minArray[0] = minRow;
	minArray[1] = minCol;
	minArray[2] = minValue;
	minPointer = minArray;
	return minPointer;
}


/**��ʼ������,ʹ�������
**/
void initGraph()
{
	int i, j;
	srand(time(NULL));    //�Ե�ǰʱ����Ϊ���������
	for (i = 0; i<N; i++)
	{
		c[i] = -1;
		t[i] = i;
		for (j = 0; j<N; j++)
		{

			//�ڵ������ɴ�
			if (i == j)
			{
				graph[i][j] = INFINITY;
				continue;
			}
			graph[i][j] = rand() % 100 + 1;
		}
	}

	/**	for(i=0;i<N;i++)
	{
	for(j=0;j<N;j++)
	if(i==0||i==1||j==0||j==1)
	graph[i][j]=INFINITY;

	}
	graph[1][0]=3;
	graph[0][1]=20;
	**/
	printf("��ʼ��ͼ�νṹ*************:\n\n");
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			if (graph[i][j] == INFINITY)
			{
				printf("%-10s", "INFINITY");
			}
			else
				printf("%-10d", graph[i][j]);
		}
		printf("\n");
	}


}


