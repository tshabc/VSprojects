#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>

// 数组类型练习函数
int studyArray()
{
	typedef int array[5];
	array myarry;
	for (int i = 0; i < 5;i++)
	{
		myarry[i] = i;
	}

	for (int  i = 0	; i < 5; i++)
	{
		printf("myarry[%d] = %d\n", i, myarry[i]);
	}
	return 0;
}
// 指针数组类型练习函数
void studyPoitArray()
{
	int *asdf[10];
	typedef int *array[5]  ; 
	array myarray;
	for (int  i = 0; i < 5; i++)
	{
		myarray[i] = (int*)malloc(40);
		for (int  j = 0; j < 10; j++)
		{
			myarray[i][j] = j + 1;
		}
		printf("myarry[%d] = %d\n", i, myarray[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("myarry[%d][%d] = %d\n", i,j, myarray[i][j]);
		}
	}

}
//数组指针
void shuzuZhizhen()
{
	/*int array[2][3];
	int *p;
	p = *array;
*/
	printf("数组指针\n");
	typedef int array[5];
	int b[5];
	array *myarray; //这是一个数组指针类型
	// myarray  存储的是一个 数组的地址
	myarray = &b;
	for (int i = 0; i < 5; i++)
	{
		(*myarray)[i] = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("(*myarray)[i] = %d \n", (*myarray)[i]);
	}


}


typedef struct _teacher 
{
	char *name;
	int number;
	int age;
}teacher;

int main02()
{
	studyPoitArray();
	studyArray();
	shuzuZhizhen();
	
	teacher *t = NULL;
	
	printf("&(t->age) = %d",&(t->age)); //结构体偏移量

	system("pause");
	
	
	return 0;
}


int main01()
{
	char c[100] = { 0 };
	char c2[100] = { 0 };
	char c3[5] = { 'a', 'b', 'c', 'd', 'e' };
	char * p1 = c;
	char * p2 = c2;
	char *test = "asdfas";
	char  test2[] = "asdf";
	printf("%d\n", sizeof(test));
	printf("%d\n", strlen(test));
	printf("%d\n", sizeof(c));
	printf("%d\n", strlen(c));
	printf("%d\n", sizeof(test2));
	printf("c3  %d\n", sizeof(c3));

	strcpy(c, "abcdefg");
	while (*p1!= '\0')
	{
		*p2 = *p1;
		p2++;
		p1++;
	}
	printf("%d\n", strlen(c));
/*

	for (int i = 0;i<sizeof(c)/sizeof(*c);i++) 
	{
	printf("%c\n", c2[i]);

	}*/


	system("pause");
	return 0;
}