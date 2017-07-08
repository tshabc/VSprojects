#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Utils.h"
using namespace std;
/*
	���������㷨˼��
	������������С��������
	ѡ��һ�����ݵ�������a��ͨ��һ�����򣬽�����С��a�ķ���a��ߣ�����a�ķ���ar �ұ� ����ʵ��һ��������̣�
	Ȼ��� a ��߸��ұߵ��������ݵ��������飬��ͬ������������
	���������Ҫ��ס������� �����±�
*/
// ���з���
int grouping(int *array, int low, int hight)
{
	if (array == NULL)
	{
		printf("param error");
		return -1;
	}
	int temp = array[low]; // ������ߵ�Ϊ����
	while (low < hight) 
	{
		while (((low<hight) && (array[hight]>= temp))) 
		{
			hight--; //�� �ұߵ������ڻ�׼���Ǿͼ��������� С�ڻ�׼������ ���ҵ�֮������ѭ�� ���׼���� 
		} 
		swapNum(array, low, hight); //���ʱ�� array[hight] �� = ��׼����
		while ((low<hight)&&(array[low]<=temp))
		{
			low++; //��ߵ����� С�ڻ�׼��ʱ���ý��� �����������Ҵ��ڻ�׼��
		}
		swapNum(array, low, hight); // ���ʱ���׼���ܵ������ array[low] = ��׼����
	}
	cout << "low = " << low << endl << "hight = " << hight << endl; //��������������ֿ϶�ָ��ͬһ����������
	return low;
}

void quckSort(int * array, int low, int hight)
{
	if (array == NULL)
	{
		printf("param error");
		return;
	}
	if (low < hight)	// �����±�ֱ�ָ��ĳ�������˵�ʱ�� �������ᷨ ����
	{
		int center = grouping(array, low, hight); //�ҵ��м��
		 //���м�����һ��
		quckSort(array, low, center - 1);
		//���ұ�һ��
		quckSort(array, center + 1, hight);
	}
}

//��дһ��
int getcenterNumber(int *array,int low,int hight)
{
	if (NULL == array)
	{
		cout << __FUNCTION__ << __FILE__ << __LINE__ << endl;
		abort();
	}
	int  number = array[low];
	while (low<hight)
	{
		while (low<hight&&array[hight]>=number)
		{
			hight--;
		}
		int temp = 0;
		temp = array[low];
		array[low] = array[hight];
		array[hight] = temp;
		while (low<hight && array[low] <=number)
		{
			low++;
		}
		temp = array[hight];
		array[hight] = array[low];
		array[low] = temp;
	}
	return low;
}
void quckSort01(int * array, int low, int hight)
{
	if (NULL == array)
	{
		cout << __FUNCTION__ << __FILE__ << __LINE__ << endl;
		return;
	}
	int center = 0;
	if (low<hight)
	{
		center = getcenterNumber(array, low, hight);
		quckSort01(array, low, center - 1);
		quckSort01(array, center + 1, hight);
	}
}

int main03(int args,char*argus[])
{
	int array[] = { 32, 15, 1, 5, 87, 10, 96, 54, 3, 8, 45, 6 };
	int length = sizeof(array) / sizeof(array[0]);
	//quckSort(array, 0, 11);
	quckSort01(array, 0, length - 1);
	coutArray(array, length);

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
