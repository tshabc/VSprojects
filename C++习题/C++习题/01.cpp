#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

#define  N 8

int main01(int args,char*argus[])
{
	int i;
	int j;
	int k;

	for (i = 0; i < N; i++)
	{
		for (k = 0; k < i;k++)
		{
			cout << "*";
			for (j = 0; j <i - 1 ; j++)
			{
				cout << ".";
			}
		}

		cout << endl;
	}

	
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
