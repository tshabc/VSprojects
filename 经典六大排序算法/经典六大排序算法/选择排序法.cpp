#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Utils.h"
using namespace std;
/*
	算法思想
	在没有排序的散列中 选择第一个做为基准，然后在散列中找一个最小的跟选择出来的一个做比较
	根据排序要求进行交换
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
				min = j;//找到需要交换的右侧坐标
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
//又做了一次，按照自己的理解。从剩下的里面找到最小的坐标，返回去
//脑补 左边是已经排序完成的，右边是没排序的
//选择排序的 对比是在右边没排序的数列中，从没排序的里面找出最小的数，放到排序好的最后面就OK了
int findSmall(int *array,int begin,int end) // 从一个数组里 找出 begin 到end之间 的最小元素坐标
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
		cout << "参数不对" << endl;
		return;
	}
	int small = 0; 
	int i = 0, j = 0;
	for ( i = 0; i < length;i++)
	{
		small = findSmall(array, i,length - 1); // 每一次都是一个最小的数跟前面 的数交换
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
