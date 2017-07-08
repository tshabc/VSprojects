#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;
// 一个行数为N的螺旋矩阵打印方法
#define  N 5
void luoxuanJZ()
{
	int round = 0;
	int i = 0, j = 0, number = 1;
	int array[N][N] = { 0 };
	int n = N;
	for (round; round < N / 2; round++)
	{
		for (j; j < n - 1; j++) //组建第一行数据
		{
			array[i][j] = number++;
		}
		for (i; i < n - 1; i++)
		{
			array[i][j] = number++;
		}
		for (j; j>round; j--)
		{
			array[i][j] = number++;
		}
		for (i = n - 1; i > round; i--)
		{
			array[i][j] = number++;
		}
		j++; i++; n--; //number -= 1;
	}
	if (N % 2 != 0)
	{
		array[i][j] = number;
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			//printf("%d\t", array[i][j]);
			cout << setw(3) << array[i][j];
		}
		printf("\n");
		//cout << setw(3) << endl;
	}
	cout << endl << endl;
}
//横向的数字矩阵
void hengxiangJZ(int number/*number几行几列*/)
{
	if (number == 1)
	{
		cout << number << endl;
	}
	int ** array;  //这里应该用动态申请内存的方式进行
	array = (int **)malloc(sizeof(int *)*number);
	for (int i = 0; i < number;i++)
	{
		array[i] = (int *)malloc(sizeof(int)*number);
	}
	int n = 1;
	for (int i = 0; i < number;i++)
	{
		for (int j = 0; j < number;j++)
		{
			array[i][j] = n++;
		}
	}
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			cout << setw(3) << array[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < number;i++)
	{
		free(array[i]);
	}
	free(array);
}
int main09(int args,char*argus[])
{
	luoxuanJZ();
	hengxiangJZ(5);
	char*c1 = "abc";
	char*c2 = "efg";
	if (*c1 >*c2)
	{
		cout << "c1 > c2" << endl;
	}
	else
	{
		cout << "c1 < c2" << endl;
	}
	if (strcmp(c1,c2)<0)
	{
		cout << "c1 < c2" << endl;
	}
	else if (strcmp(c1,c2)== 0)
	{
		cout << "c1 = c2" << endl;
	}
	else if (strcmp(c1,c2)>0)
	{
		cout << "c1 > c2" << endl;
	}
	char* c3 = "eerrrrqqAB33333ABa333333ABjsfdsfdsa";

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
