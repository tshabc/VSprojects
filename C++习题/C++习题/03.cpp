#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*	
	静态变量在函数里的使用现象
*/
using namespace std;
static int  j;
void fun01()
{
	static int i = 0;
	i++;
	cout << "i = " << i << endl;
}
void fun02()
{
	j = 0;
	j++;
	cout << "j = " << j << endl;
}
void fun03(int b[100])
{
	sizeof(b);
	cout << "sizeof(b) = " << sizeof(b) << endl;
}
void shuzutest()
{
	//数组地址+1 跟数组首元素+1的效果
	int a[10] = {1,2};
	char c[10] = {'a'};
	printf("数组a的地址 : %d \n",&a);
	printf("数组c的地址 : %d \n", &c);
	printf("数组地址跳一下的结果 &a + 1 = : %d \n", &a + 1 );  // 数组地址跳一下就是 数组的长度* 字节数
	printf("数组地址跳一下的结果 &c + 1 = : %d \n", &c + 1);  // 数组地址跳一下就是 数组的长度* 字节数
	printf("数组a首元素的地址 : %d \n", a);

}
int main03(int args,char*argus[])
{

	for (int i = 0; i < 10;i++)
	{
		fun01();
		fun02();
	}
	cout<<"Hello World"<<endl;

	int*p = NULL;

	cout << "sizeof(p) = " << sizeof(p) << endl;
	cout << "sizeof(*p) = " << sizeof(*p) << endl;
	int a[100] = { 0 };
	cout << "sizeof(a) = " << sizeof(a) << endl;
	cout << "sizeof(a[100]) = " << sizeof(a[100]) << endl; // a[100]  注意本例中的 100 是代表第100个元素
	cout << "sizeof(&a) = " << sizeof(&a) << endl;
	cout << "sizeof(&a[0]) = " << sizeof(&a[0]) << endl;
	fun03(a);
	shuzutest();

	system("pause");
	return 0;
}
