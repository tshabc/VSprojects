#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Utils.h"
using namespace std;

void maoPaoSort(int *array, int length)
{
	if (array == NULL)
	{
		cout << "param error" << endl;
		return;
	}
	int i = 0;
	int j = 0;
	for (i = 0; i < length;i++)
	{
		for ( j = i+1; j < length; j++)
		{
			if (array[i]>array[j])
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}


}

int main03(int args,char*argus[])
{
	int array[] = { 32, 6, 1, 5, 87, 6, 96, 54, 3, 5, 45, 6 };
	int length = sizeof(array) / sizeof(array[0]);

	maoPaoSort(array, length);
	coutArray(array, length);

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
