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
//�Ե�ַ�ļ������
void CPUcalc()
{
	Teacher* t = NULL;
	int i = 0;
	i = (int)&(t->age); //Ѱַ���� ȡ�˸���ַ ת�ѵ�ַת��int ��� ����һ��CPU�ļ�����̣���û�з��� (t->age) ���ڴ�

	cout << "i = " << i << endl;

}

//���ļ��Ĳ�����ϰ
void fuxiFile()
{
	/* char * c = "C:\\Users\\HuaLI\\Documents\\Visual Studio 2013\\Projects\\C++ϰ��\\�����ı�.txt";//·���� \ ��Ҫת�� д�� \\  */
	char * c = "C:/Users/HuaLI/Documents/Visual Studio 2013/Projects/C++ϰ��/�����ı�.txt";//·���� / ����Ҫת�� 
	char * c1 = "C:/Users/HuaLI/Documents/Visual Studio 2013/Projects/C++ϰ��/�����ı�2.txt";
	FILE *fp = NULL; 
	FILE*fp1 = NULL;
	char readbuf[512] = {0};
	char*p = NULL;
	fp = fopen(c, "r");
	if (NULL ==fp)
	{
		cout << "��ʧ��" << endl;
	}
	else
	{
		cout << "�򿪳ɹ�" << endl;
	}
	fp1 = fopen(c1, "at");
	if (NULL == fp1)
	{
		cout << "��ʧ��" << endl;
	}
	else
	{
		cout << "�򿪳ɹ�" << endl;
	}
	if (NULL != fp && NULL != fp1)
	{
		while ( !feof(fp) ) //���û���ļ���β ��һֱ��
		{
			p = fgets(readbuf, 512, fp);
			if (p == NULL)
			{
				printf(" ����\n");
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
	int * prt1 = (int *)(&a+1);// int �� ��ַ + 1 �Ǽ���4
	int * ptr2 = (int*)((int)a+1); // int �� ����+1 ���Ǽ��� 1
	
	printf("%x,%x\n", prt1[-1], *ptr2);
	printf("%d,%d\n", prt1[-1], *ptr2);//����ת���ɵ�ַ֮�� �ڴ�������־Ͳ�һ����

}
void testStrlen()
{
	char aa[10] ;
	cout << strlen(aa) << endl;// �㲻��ʼ����������з��ӵ����ݣ�˭֪������ڴ�����ɶ
	cout << sizeof(aa) << endl;//����ǲ��ڴ�����ж����ֽڵ�
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
