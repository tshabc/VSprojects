#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
//编程练习
void questingOne(int f)
{
	float a = 0;
	float k = 0;
	a = 5 * (f - 32) / 9;
	k = 273.16 + a;
	/*cout << "摄氏温度 = " << a << endl;
	cout << "绝对温度 = " << k << endl;*/
	printf("摄氏温度 = %f\n", a);
	printf("绝对温度 = %f\n", k);
}
void qestionTwo()
{
	char * name[] = { "zhanghua", "lina" ,"wanggang"};
	for (int i = 0; i < 3;i++)
	{
		printf("%s\n", name[i]);
	}
}
int qestionThree(int number)
{
	int r = 0;
	int a = number / 100;
	int b = (number / 10) - (a*10);
	int c = number - a * 100 - b * 10;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	r = a + b + c;
	return r;
}
void questionFour()
{
	float sn = 100.0, hn = sn / 2;
	int n;
	for (n = 1; n <= 10;n++)
	{
		sn = sn + 2*hn;
		hn = hn / 2;
	}
	cout << "sn = " << sn << endl;
	cout << "hn = " << hn << endl;
}void swap01(int *p1,int *p2)
{
	/*int *p;//没有内存空间存储数据只是一个地址变量
	*p = *p1;
	*p1 = *p2;
	*p2 = *p;*/

}
void test01()
{
	int w[2][3] = { 0 };
	int (*pw)[3];
	pw = w;
	cout << *(w[0] + 2) << endl;
	cout << *(pw + 1)[2] << endl;
	cout <<w<< pw <<&w<< endl;
	cout << pw + 1 << endl;
	cout << pw[0][0] << endl;
	cout << *(pw[1] + 2) << endl;
}
void test02()
{
	//atoi
	char * n = "123456";
	int num = 0;
	for (int i = 0; i < strlen(n);i++)
	{
		num = num * 10 + (n[i] - 48); /* 不能强转 (int)n[i]*/
	}
	cout << num << endl;

}
void test03()
{
	//itoa
	int number = 123456;
	int y = number % 10;
	char c[10] = {0};
	char c1 = ' ';
	int i = 0;
	while (number != 0)
	{
		y = number % 10;
		number /= 10;
		//cout << "y = " << y << endl;
		c1 = y - (0 - '0');
		c[i] = c1;
		i++;
	} 
	cout << "itoa 结果：";
	for (i = strlen(c) - 1; i >= 0;i--)
	{
		cout << c[i];
	}
	cout << endl;
	
}
int main04(int args,char*argus[])
{
	test01();
	test02();
	test03();
	int  a = 12;
	int aa[8] = {1,2,3,4,5,6,7,8};
	int *p = aa;
	int x = 1;
	char c = '0';
	cout << "*(p+6) = " << *(p + 6) << endl;
	cout << "*p = " << *p  << endl;
	char * aaa[2] = { "sdf", "dsf" };
	char *s = "\t\\Name\\address\n";
	cout << "strlen = " << strlen(s) << endl;
	printf("%s\n", s);
	/*	scanf("%c", &c);*/
	//x = a = 3, 6 * a;
	//a /= a + a;
// 	a -= a + a;
// 	cout << "a = " << a << endl;
// 	cout << "x = " << x << endl;
// 	cout<<"Hello World"<<endl;
	int  f = 34;
	int number = 132;
	int result = 0;
	questingOne(f);
	qestionTwo();
	result = qestionThree(number);
	cout << "结果是 = " << result << endl;
	int b = '9' - 48;
	cout << b << endl;
	questionFour();

	swap01(&a, &x);
	cout << a << endl;
	cout << x << endl;

	system("pause");
	return 0;
}
