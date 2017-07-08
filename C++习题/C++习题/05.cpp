#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
typedef struct  student
{
	long num;
	int score;
	struct student * next;

}student;
struct student * create()
{
	
	student * head;
	head = NULL;

	return head;
}
struct st
{
	int a;
	char b;
	double c;
};
int main05(int args,char*argus[])
{
	st d[2] = { {}, {} };
	int a;
	cin >> a;
	cout << a << endl;
	int i = 0,j = 0;
	while (i<15)
	{
		j++;
		i += ++j;
	}
	cout << i << " " << j << endl;
	int  aa[5] = {0,1,2,3,4},*p;
	p = &aa[3];
	cout << "*--p = " << *--p << endl;

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}

