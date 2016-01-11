#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "seqList.h"
using namespace std;

typedef struct Teacher
{
	char name[20];
	int age;
}Teacher;

int jsurph() // 约瑟夫环
{
	int pe[8] = { 0 };
	int remainNum = 8;
	int count = 0;
	int i = 0;
	for (i = 0;;)
	{
		if (pe[i] != 1)
		{
			count++;
		}
		if (count >= 3)
		{
			count = 0;
			pe[i] = 1;
			remainNum--;
		}
		if (remainNum <= 0)
		{
			break;
		}
		i++;
		if (i > 7)
		{
			i = 0;
		}
	}

	cout << "最后出局的是第 " << i + 1 << " 个人" << endl;
	cout << "跳出来了" << endl;
	return i + 1;
}
int main(int args,char*argus[])
{
	seqList* mylist = NULL;
	mylist = seqList_create(5);
	Teacher t1, t2, t3, t4, t5;
	t1.age = 10;
	t2.age = 20;
	t3.age = 30;
	t4.age = 40;
	t5.age = 50;
	seqList_insert(mylist, (seqListNode*)&t1, 0);
	seqList_insert(mylist, (seqListNode*)&t2, 0);
	seqList_insert(mylist, (seqListNode*)&t3, 0);
	seqList_insert(mylist, (seqListNode*)&t4, 0);
	seqList_insert(mylist, (seqListNode*)&t5, 0);
	for (int i = 0; i < 5; i++)
	{
		Teacher* temp = (Teacher*)seqList_getNode(mylist, i);
		printf("temp->age = %d \n", temp->age);
	}
	

	//jsurph();
	
	system("pause");
	return 0;
}
