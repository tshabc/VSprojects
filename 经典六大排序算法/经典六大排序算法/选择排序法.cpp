#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Utils.h"
using namespace std;
/*
	�㷨˼��
	��û�������ɢ���� ѡ���һ����Ϊ��׼��Ȼ����ɢ������һ����С�ĸ�ѡ�������һ�����Ƚ�
	��������Ҫ����н���
*/
void choiceSort(int * array,int length)
{
	cout << sizeof(array) << endl;
	int temp = 0;
	int min = 0;
	int change = 0;
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		temp = i;
		for (min = i,j = i + 1; j < length; j++)
		{
			if (array[min] > array[j ])
			{
				min = j;//�ҵ���Ҫ�������Ҳ�����
			}
		}
		cout << min << endl;
		if (array[temp] > array[min])
		{
			change = array[min];
			array[min] = array[temp];
			array[temp] = change;		
		}
	}
}
//������һ�Σ������Լ�����⡣��ʣ�µ������ҵ���С�����꣬����ȥ
//�Բ� ������Ѿ�������ɵģ��ұ���û�����
//ѡ������� �Ա������ұ�û����������У���û����������ҳ���С�������ŵ�����õ�������OK��
int findSmall(int *array,int begin,int end) // ��һ�������� �ҳ� begin ��end֮�� ����СԪ������
{
	if (NULL == array)
	{
		abort();
		cout << "asdfasdf" << endl;
		return 0;
	}
	int temp = begin;
	for (int i = begin; i <= end;i++)
	{
		if (array[i] < array[temp])
		{
			temp = i;
		}		
	}
	return temp;
}
void chiceSort01(int *array, int length)
{
	if (NULL == array)
	{
		cout << "��������" << endl;
		return;
	}
	int small = 0; 
	int i = 0, j = 0;
	for ( i = 0; i < length;i++)
	{
		small = findSmall(array, i,length - 1); // ÿһ�ζ���һ����С������ǰ�� ��������
		int temp = 0;
		temp = array[i];
		array[i] = array[small];
		array[small] = temp;
	}
}

int main06(int args,char*argus[])
{
	int array[] = { 32, 15, 1, 5, 87, 10, 96, 54, 3, 8, 45, 6 };
	cout << sizeof(array)/sizeof(array[0]) << endl;
	int length = sizeof(array) / sizeof(array[0]);
	//choiceSort(array, 12);
	chiceSort01(array, length);
	
	
	coutArray(array, 12);
/*
	int min = 0;
	int length = 12;
	for (int j = 0; j < length-1; j++)
	{
		if (array[min] > array[j+1])
		{
			min = j + 1;
		}

	}
	cout << "min = " << min << endl;
	*/
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
