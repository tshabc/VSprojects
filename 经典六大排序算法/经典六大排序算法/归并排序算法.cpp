#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Utils.h"

using namespace std;
void mergeAction(int *array, int *dec, int low, int mid, int hight)
{
	if (array == NULL || dec == NULL)
	{
		cout << "param error " << endl;
		return;
	}
	int i = low;
	int j = mid + 1;
	int k = low;
	while (i <= mid&&j <= hight)
	{
		if (array[i] < array[j])
		{
			dec[k++] = array[i++];
		}
		else
		{
			dec[k++] = array[j++];
		}
	}
	while (i <= mid)
	{
		dec[k++] = array[i++];
	}
	while (j <= hight)
	{
		dec[k++] = array[j++];
	}

}
void mergeSort(int *array, int *dec, int low, int hight, int max)
{
	if (array == NULL || dec == NULL)
	{
		cout << "param error " << endl;
		return;
	}
	if (low == hight)
	{
		dec[low] = array[low];
	}
	else
	{
		int mid = (low + hight) / 2;
		int *space = (int *)malloc(sizeof(int)*max);
		mergeSort(array, space, low, mid, max);
		mergeSort(array, space, mid + 1, hight, max);
		mergeAction(space,dec , low, mid, hight);
		if (space != NULL)
		{
			free(space);
		}
	}
}
//�ٴ�ѧϰ
//�㷨˼�룺��ԭ���а���������˼������������������ ���ϲ�
void mergeSort01(int * array,int * dec,int low,int hight,int max)
{
	if (NULL == array)
	{
		cout << "error" << endl;
		abort();
	}
	/*
	//���� Ѱ���м��±� ���� 
	int temp = array[low];
	while (low<hight)
	{
		while (low<hight && array[hight]>=temp)//��Ϊ temp  = array��low�� ���Դ�hight ��ʼ�ȽϺ�,�ұ�>= ����Ķ����ò�����ֻ��Ҫ��hight ָ�����Ƽ�����
		{
			hight--;
		}
		int t = array[low];
		array[low] = array[hight];
		array[hight] = t;
		while (low<hight && array[low]<=temp)
		{
			low++;
		}
		int t = array[low];
		array[low] = array[hight];
		array[hight] = t;

	}
	return low;
	*/
	if (low=hight)
	{
		dec[low] = array[low];
	}
	else
	{
		int mid = (low + hight)/2;
		int * space = (int*)malloc(sizeof(int)*max);
		mergeSort01(array, space, low, mid, max);
		mergeSort01(array, space, mid + 1, hight, max);
		mergeAction(space, dec, low, mid, hight);
		if (space != NULL)
		{
			free(space);
		}
	}


}
int main(int args, char*argus[])
{

	int array[] = { 32, 6, 1, 5, 87, 6, 96, 54, 3, 5, 45, 6 };
	int length = INTARRAY_LENGTH(array);

	mergeSort(array, array, 0, 11,length);

	coutArray(array,length);

	cout << "length = " << length << endl;


	system("pause");
	return 0;
}
