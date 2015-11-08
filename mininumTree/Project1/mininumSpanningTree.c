#include<omp.h>
#include<stdio.h>
#include<malloc.h>
#include<time.h>       //�����������Ҫ
#include<stdlib.h>
#define INFINITY 65535 //�ڵ㲻�ɴ�
#define N 2000    //ͼ�Ľڵ����

void initGraph();
int createMininumTree();
int* getMininumArray(int, int[]);
void printGraph();
void printMininumTree();
void initOriginalData();
void copyOriginalData();

//�����ڽӾ������ʽ�洢ͼ,tempֻ�Ǳ����ʼ��ʱ�������
int graph[N][N], originalGraph[N][N];
int c[N], originalC[N];       //��С�������Ľڵ㼯��
int t[N], originalT[N];       //ʣ��û�м�����С�������Ľڵ�
int mininumTreeIndex[N - 1][3];  //��С��������·��������1,2,3�зֱ�����ϵ�����С��С�Ȩֵ��
float efficiency;       //���ٱ�


/** ʹ��prime�㷨����С�����������п�����߳����Ч�ʣ��������ԣ�
�����ڼ�����СȨֵʱ��ͬʱ��c�и��ڵ㵽t�нڵ�ĸ�����Сֵ��Ȼ��Ƚϡ�
**/
int main()
{
	//�����߳���
	int i = 1;
	unsigned long t1, t2;
	int threadsNums = omp_get_num_procs();
	printf("�����߼�����������Ϊ%d\n\n", threadsNums);
	unsigned int singleThreadRunTime = 0;  //���߳�����ʱ��

	initGraph();
	//��ʼ��ԭʼ����
	initOriginalData();
	for (; i <= threadsNums; i++)
	{
		copyOriginalData();
		printf("�����̸߳���Ϊ��%d\n", i);
		t1 = clock();
		if (createMininumTree(i))
		{
			t2 = clock();
			printf("%d���ڵ㽨������С������������ʱ��Ϊ��%d����\t", N, t2 - t1);
			if (i == 1)
			{
				singleThreadRunTime = t2 - t1;
			}
			else
			{
				efficiency = singleThreadRunTime*1.0f / (t2 - t1);
				printf("���ٱ�Ϊ%f", efficiency);

			}


			//printf("��С�������ṹ��\n");
			//printMininumTree();
		}
		else
		{
			printf("�޷�������С������\n");
		}
		printf("\n\n");
	}

	return 0;
}
/*
������С������,����0����������С������
���������С������
���� parallelThreadsNum�������߳���
*/
int createMininumTree(int parallelThreadsNums)
{
	int visitedCount = 1;          //�Ѿ���ӵ�����c�еĽڵ�����
	int i = 0, j = 0, k = 0;
	int minValue = INFINITY, minRow, minCol;
	int flag = 0;                    //�Ƿ��ܹ�������С�������ı��
	c[0] = 0;                        //����һ���ڵ����c�У�ͬʱ��t��ɾ��
	t[0] = -1;                       //t[k]=-1���������Ϊk�Ľڵ��Ѿ���t��ɾ��
	int threadCountFlag = 0;   //�����������̸߳�����ǣ�ֻ�ڵ�һ������ʱ�����

	//һ�����һ���ڵ㵽c��ͬʱ��v��ɾ��һ���ڵ�
	for (i = 0; i < N; i++)
	{
		flag = 0;
		minValue = INFINITY;
		minRow = INFINITY;
		minCol = INFINITY;
		/**
		�õ���c��tȨֵ��Сֵ
		**/
		//������Զ�̬�ı��̸߳���
#pragma omp parallel num_threads(parallelThreadsNums)
		{
			int *minArrayPointer;          //��������ָ��
#pragma omp for schedule(dynamic,2)
			for (j = 0; j < visitedCount; j++)
			{
				//#pragma omp flush
				//				if (!threadCountFlag)
				//				{
				//					threadCountFlag = 1;
				//					printf("��������ʹ���̸߳���%d\n", omp_get_num_threads());
				//				}
#pragma omp flush
				minArrayPointer = getMininumArray(c[j], t);

#pragma omp critical
				if (*(minArrayPointer + 2) < minValue)
				{
					minRow = *(minArrayPointer);
					minCol = *(minArrayPointer + 1);
					minValue = *(minArrayPointer + 2);
					flag = 1;
				}
			}

		}
		/**
		��ͼ�й�����ͨͼ,����ȴ�forѭ�����ִ�����֮������ж�
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
	//printf("&minCol=%d\t&minArray=%d", &minCol,minArray);
	int j, *minPointer;
	//printf("�߳�%d\n", omp_get_thread_num());
	for (j = 0; j < N; j++)
	{
		if (unVisited[j] == -1)
			continue;
		if (graph[i][j] < minValue)
		{
			minRow = i;
			minCol = j;
			minValue = graph[i][j];
		}

	}



	//	printf("�߳�id=%d\n", omp_get_thread_num());
	//printf("internal minvalue=%d\t", minValue);

	minArray[0] = minRow;
	minArray[1] = minCol;
	minArray[2] = minValue;
	minPointer = minArray;
	//#pragma omp critical
	return minPointer;
}


/**��ʼ������,ʹ�������
**/
void initGraph()
{
	int i, j;
	srand(time(NULL));    //�Ե�ǰʱ����Ϊ���������
	for (i = 0; i < N; i++)
	{
		c[i] = -1;
		t[i] = i;
		for (j = 0; j < N; j++)
		{

			//�ڵ������ɴ�
			if (i == j)
			{
				graph[i][j] = INFINITY;
				continue;
			}
			graph[i][j] = rand() % N + 1;
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
	// printf("��ʼ��ͼ�νṹ*************:\n\n");
	//printGraph();



}

/**
��ӡ��С�������ṹ*/
void printMininumTree()
{
	int i = 0;
	for (; i < N - 1; i++)
	{

		printf("����%-4d������%-4dȨֵ%-10d", mininumTreeIndex[i][0], mininumTreeIndex[i][1], mininumTreeIndex[i][2]);
		printf("\n");
	}
}
/**
��ӡͼ�νṹ
*/
void printGraph()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
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
/*
��ʼ��ԭʼ���ݣ�����ԭʼ����
*/
void initOriginalData()
{
	int i = 0, j = 0;
	for (; i < N; i++)
		for (j = 0; j < N; j++)
			originalGraph[i][j] = graph[i][j];
	for (i = 0; i < N; i++)
	{
		originalC[i] = 0;
		originalT[i] = 0;
	}




}
/*
���ݽ��г�ʼ����ÿ�������߳������ı�ʱ����ã���ֵ����
*/
void copyOriginalData()
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			graph[i][j] = originalGraph[i][j];

	for (i = 0; i < N; i++)
	{
		c[i] = originalC[i];
		t[i] = originalT[i];
	}
}



