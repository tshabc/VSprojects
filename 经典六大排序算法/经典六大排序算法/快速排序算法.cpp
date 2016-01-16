#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Utils.h"
using namespace std;
/*
	快速排序算法思想
	假设需求是由小到大排序
	选择一个数据当做枢轴a，通过一趟排序，将所有小于a的放在a左边，大于a的放在ar 右边 （其实是一个分组过程）
	然后把 a 左边跟右边的两个数据当做新数组，用同方法进行排序
	排序过程中要记住新数组的 两端下标
*/
// 进行分组
int grouping(int *array, int low, int hight)
{
	if (array == NULL)
	{
		printf("param error");
		return -1;
	}
	int temp = array[low]; // 以最左边的为枢轴
	while (low < hight) 
	{
		while (((low<hight) && (array[hight]>= temp))) 
		{
			hight--; //当 右边的数大于基准，那就继续往左找 小于基准的数字 ，找到之后跳出循环 与基准交换 
		} 
		swapNum(array, low, hight); //这个时候 array[hight] 就 = 基准数字
		while ((low<hight)&&(array[low]<=temp))
		{
			low++; //左边的数字 小于基准的时候不用交换 ，继续往右找大于基准的
		}
		swapNum(array, low, hight); // 这个时候基准又跑到左边了 array[low] = 基准数字
	}
	cout << "low = " << low << endl << "hight = " << hight << endl; //到最后这两个数字肯定指在同一个数字上面
	return low;
}

void quckSort(int * array, int low, int hight)
{
	if (array == NULL)
	{
		printf("param error");
		return;
	}
	if (low < hight)	// 当此下标分别指在某数组两端的时候 进行枢轴法 分组
	{
		int center = grouping(array, low, hight); //找到中间点
		 //按中间点左边一组
		quckSort(array, low, center - 1);
		//，右边一组
		quckSort(array, center + 1, hight);
	}
}



int main04(int args,char*argus[])
{
	int array[] = { 32, 6, 1, 5, 87, 6, 96, 54, 3, 5, 45, 6 };
	int length = sizeof(array) / sizeof(array[0]);
	quckSort(array, 0, 11);
	coutArray(array, length);

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
