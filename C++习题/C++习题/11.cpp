#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
struct Teacher
{
	char*name;
	int age2;
	char buf[32];
	int age;
	
};
//对地址的加深理解
void CPUcalc()
{
	Teacher* t = NULL;
	int i = 0;
	i = (int)&(t->age); //寻址操作 取了个地址 转把地址转成int 输出 这是一个CPU的计算过程，并没有访问 (t->age) 的内存

	cout << "i = " << i << endl;

}

//对文件的操作复习
void fuxiFile()
{
	/* char * c = "C:\\Users\\HuaLI\\Documents\\Visual Studio 2013\\Projects\\C++习题\\测试文本.txt";//路径名 \ 需要转义 写成 \\  */
	char * c = "C:/Users/HuaLI/Documents/Visual Studio 2013/Projects/C++习题/测试文本.txt";//路径名 / 不需要转义 
	char * c1 = "C:/Users/HuaLI/Documents/Visual Studio 2013/Projects/C++习题/测试文本2.txt";
	FILE *fp = NULL; 
	FILE*fp1 = NULL;
	char readbuf[512] = {0};
	char*p = NULL;
	fp = fopen(c, "r");
	if (NULL ==fp)
	{
		cout << "打开失败" << endl;
	}
	else
	{
		cout << "打开成功" << endl;
	}
	fp1 = fopen(c1, "at");
	if (NULL == fp1)
	{
		cout << "打开失败" << endl;
	}
	else
	{
		cout << "打开成功" << endl;
	}
	if (NULL != fp && NULL != fp1)
	{
		while ( !feof(fp) ) //如果没到文件结尾 就一直读
		{
			p = fgets(readbuf, 512, fp);
			if (p == NULL)
			{
				printf(" 、、\n");
				return;
			}
			printf("%s\n",readbuf);
			printf("%s\n", p);
			fputs(readbuf, fp1);
		}
	}
	if (fp!=NULL)
	{
		fclose(fp);
	}
	if (fp!=NULL)
	{
		fclose(fp1);
	}
}
void testBuchang()
{
	int a[6] = { 1, 2, 3, 4, 5 ,6};
	int * prt1 = (int *)(&a+1);// int 型 地址 + 1 是加了4
	int * ptr2 = (int*)((int)a+1); // int 型 数字+1 就是加了 1
	
	printf("%x,%x\n", prt1[-1], *ptr2);
	printf("%d,%d\n", prt1[-1], *ptr2);//所以转换成地址之后 内存里的数字就不一样了

}
void testStrlen()
{
	char aa[10] ;
	cout << strlen(aa) << endl;// 你不初始化里面可能有繁杂的数据，谁知道这块内存里是啥
	cout << sizeof(aa) << endl;//这个是测内存块是有多少字节的
}
int main(int args,char*argus[])
{
	CPUcalc();

	//fuxiFile();
	testBuchang();
	//cout<<"Hello World"<<endl;

	testStrlen();
	system("pause");
	return 0;
}
