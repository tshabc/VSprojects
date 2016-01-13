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

int main02(int args,char*argus[])
{
	int array[] = { 32, 6, 1, 5, 87, 6, 96, 54, 3, 5, 45, 6 };
	int length = sizeof(array) / sizeof(array[0]);
	insertSort(array, length);
	coutArray(array, length);

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
