#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
// ì³²¨ÄÇÆæÊýÁÐ 

int pheponatch(int  num)
{

	int i = 1;
	int j = 1;
	int k = 0;
	int temp = 0;
	int goal = 0;
	while (i<=num)
	{
		if (i<3)
		{
			j = 1;
			goal = 1;
		}
		else
		{
			temp = goal;
			goal = goal + j;
			j = temp;
		}
		i++;
	}
	//cout << goal << endl;

	return goal;
}
//¸´Ï°
void pheponatch01(int m)
{
	int i = 1, j= 1;
	int k = i + j;
	cout << i << endl << j << endl;
	while (1)
	{
		k = i + j;
		i = j;
		j = k;
		if (k>m)
		{
			break;
		}
		cout /*<< i << j*/ << k << endl;
	}
}
int main02(int args,char*argus[])
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
	//	cout << pheponatch(i) << endl;
	}
	int *a[10];
	int b = 1;
	int  *const aa = &b;

	pheponatch01(13);
	cout<<"Hello World"<<endl;

	system("pause");
	return 0;
}
