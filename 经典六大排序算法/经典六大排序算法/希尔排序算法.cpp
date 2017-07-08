#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Utils.h"
using namespace std;
/*
	希尔排序算法思想
	
	通过假分组方法进行分组排序，两两数据进行比较，满足条件交换
	分组的间隔:假设数组长度 length ,组数 为 group = length/3 + 1 

*/

void xierSort(int *array, int length)
{
	if (array == NULL)
	{
		cout << "error" << __FILE__ << __FUNCTION__ << __LINE__ << endl;
		return;
	}
	int i = 0 ,j = 0;
	int group = length;
	do{
		group = group / 3 + 1;
		for (i = group; i <length;i= i+group)
		{
			int temp = array[i];
			for (j = i - group; j >= 0 && array[j]> temp; j = j-group)
			{
				array[j+group] = array[j];
			}
			array[j+group] = temp;
			cout << "交换" << endl;
			coutArray(array, 12);
		}

	} while (group > 1);

}
//再写一遍 希尔排序是 算出下标间隔 ,把间隔两头的元素两两进行排序交换
//
void xierSort01(int * array,int length)
{
	if (NULL == array)
	{
		cout << __FUNCTION__ << __FILE__ << __LINE__ << endl;
		abort();
	}
	int jiange = length;
	int i = 0,j = 0;
	do
	{
		jiange = jiange / 3 + 1;
		for (i = jiange; i < length; i = i+ jiange)
		{
			int temp = array[i];
			for (j = i - jiange; j >= 0 && array[j] > temp;j = j-jiange)
			{
				array[j + jiange] = array[j];				
			}
			array[j+jiange] = temp;
			coutArray(array, 12);
		}
		
	} while (jiange > 1);

}
int main05(int args,char*argus[])
{

	int array[] = { 32, 15, 1, 5, 87, 10, 96, 54, 3, 8, 45, 6 };
	int length = sizeof(array) / sizeof(array[0]);

	//xierSort(array, length);
	xierSort01(array, length);
	coutArray(array, length);
	{
		double d[] = { 4, 8 },*p,*q,*u;
		u = d;
		p = &d[0];
		q = p + 1;
		cout << q - p << endl;
		cout << (int)q - (int)p << endl;
		cout << (int)q - (int)d << endl;
	}

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
