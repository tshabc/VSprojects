#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Utils.h"
using namespace std;


void insertSort(int array[],int length)
{
	if (array == NULL)
	{
		cout<<"param erro ";
		return;
	}
	int i = 0;
	int j = 0;
	int tempvalue = 0;
	int k = 0;
	for (i = 1; i < length;i++)
	{
		tempvalue = array[i];
		for (j = i - 1; j >= 0 && array[j]>tempvalue; j--)
		{
			array[j+1] = array[j];
		}
		array[j+1] = tempvalue; //注意循环完成之后，j 多减了 1
		//cout << "/*/*/*/*/*/******************************//"<< endl;
		//coutArray(array, length);
	}

}
//第二次来写插入法，长时间不写又忘记了
//插入法基本思想：： 认为只有一个数的数组是有序的，然后从后面的多个元素里面随便拿一个元素与前面的有序数列 一个一个的比较
//如果前面的有序数列比刚才拿出的元素大（由小到大排序），把前面的有序数列大的往后移一个位置，直到找到一个不比刚才拿出的数小的停下
void insertSort01(int *array,int lengtg)
{
	if (NULL == array)
	{
		return;
	}
	int i = 0, j = 0;
	int tempValue = 0; // 从第一个开始拿值 认为一个元素是有序的
	for (i = 1; i < lengtg;i++)
	{
		tempValue = array[i];
		j = i - 1;
		while (j >= 0 && (array[j]>tempValue))
		{			
			array[j + 1] = array[j];
			j--;
		}
		if (j!=i-1)
		{
			array[j + 1] = tempValue;
		}
	}

	
}
void insertSort02(int  array[],int length)
{
	if (NULL == array)
	{
		cout << "wrong" << endl;
	}
	int i = 0, j = 0;
	int temp = 0;
	for (i = 1; i < length;i++)
	{
		temp = array[i];
		for (j = i - 1; j >= 0;j--)//将刚才拿出的数据跟前面的有序数列对比：前面的有序数列是从 i-1 到 0 是有序的 已经排好的
		{
			if (array[j]>temp)//符合条件的数往后移一个 //注 这个地方之前打错了代码 出了 bug 调了一个多小时 (⊙﹏⊙)b  写成了 array[j>temp]  把 >temp 也包在中括号内了
			{
				array[j + 1] = array[j];//边界问题：程序第一次到这里的时候 array[j+1] 是跟array[i] 相等的 不存在多加问题
			}
			else // 找到了不比temp 小的地方
			{
				break;
			}
		}
		array[j + 1] = temp;
		//coutArray(array,length);
	}
}
//复习
void fuxi(int * array,int length)
{
	if (NULL == array)
	{
		cout<<" param error" << __FILE__ << __FUNCTION__ << __LINE__ << endl;
		return;
	}
	int i = 0, j = 0;

	for (i = 0; i < length;i++)
	{
		int temp = array[i];
		for (j = i-1; j >=0;j--)
		{
			if (array[j]>temp)
			{
				array[j + 1] = array[j];
			}
			else
			{
				break;
			}
		}
		array[j + 1] = temp;
	}
}
int main01(int args,char*argus[])
{
	int array[] = { 32, 15, 1, 5, 87, 10, 96, 54, 3, 8, 45, 6 };
	int length = sizeof(array) / sizeof(array[0]);
	//insertSort(array, length);
	//insertSort01(array, length);
	insertSort02(array, length);
	coutArray(array, length);

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
