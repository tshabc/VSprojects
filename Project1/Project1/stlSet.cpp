#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;
void mycout(int a)
{
	cout << a << endl;
}
int main06(int args,char*argus[])
{

	set<int> myset;
	for (int i = 0; i < 9;i++)
	{
		myset.insert( i + 1 );
	}
	for_each(myset.begin(), myset.end(), mycout);
	
	system("pause");
	return 0;
}
