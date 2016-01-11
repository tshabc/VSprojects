#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <list>
using namespace std;

void testList()
{
	list<int> mylist;
	for (int i = 0; i < 5;i++)
	{
		mylist.push_back(i+1);
	}

	list<int>::iterator it;
	for (it = mylist.begin(); it != mylist.end();)
	{
		
		cout << *it << endl;
		if (*it == 2)
		{
			it = mylist.erase(it);
		}
		else
		{
			it++;
		}
	}
	cout << "É¾³ýÖ®ºó" << endl;
	for (it = mylist.begin(); it != mylist.end(); it++)
	{
		cout << *it << endl;
	}
	cout << mylist.max_size() << endl;
}

int main04(int args,char*argus[])
{

	testList();

	system("pause");
	return 0;
}
