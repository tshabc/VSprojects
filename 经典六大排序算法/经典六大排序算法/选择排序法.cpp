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
				min = j;
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


int main01(int args,char*argus[])
{
	int array[] = { 32, 6 , 1, 5, 87, 6, 9654, 54, 3, 5, 45, 6 };
	cout << sizeof(array)/sizeof(array[0]) << endl;
	choiceSort(array, 12);
	
	
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
