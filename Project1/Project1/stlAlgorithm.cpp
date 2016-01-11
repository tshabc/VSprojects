#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <list>
#include <algorithm>
#include "vector"
using namespace std;
void myPrintFunc(int a)
{
	cout << "int myPrintFunc a =  " << a << endl;
}
int myCompare(const int &a,const int &b)
{
	return a > b;
}
int main05(int args,char*argus[])
{
	list<int> myList;
	vector<int> myV;
	for (int i = 0; i < 9;i++)
	{
		myList.push_back(i + 1);
		myV.push_back(i + 1);
	}
	list<int>::iterator it = myList.begin();
// 	for each (int i in myList)
// 	{
// 		cout << "i = " << i << endl;
// 	}

	for_each(it, myList.end(), myPrintFunc);
	it = myList.begin();
	myList.sort(myCompare);
	//sort(myList.begin(), myList.end(), myCompare);  注意 list 不支持 algorithm 算法里面的排序，list 自带排序算法
	sort(myV.begin(), myV.end(), myCompare);

	cout << "after sort" << endl;
	for_each(myList.begin(), myList.end(), myPrintFunc);

	system("pause");
	return 0;
}
