#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Utils.h"
using namespace std;


void insertSort(int array[],int length)
{
	if (array == NULL)
	{
		cout<<"param erro ";
		return;
	}
	int i = 0;
	int j = 0;
	int tempvalue = 0;
	int k = 0;
	for (i = 1; i < length;i++)
	{
		tempvalue = array[i];
		for (j = i - 1; j >= 0 && array[j]>tempvalue; j--)
		{
			array[j+1] = array[j];
		}
		array[j+1] = tempvalue; //ע��ѭ�����֮��j ����� 1
		//cout << "/*/*/*/*/*/******************************//"<< endl;
		//coutArray(array, length);
	}

}
//�ڶ�����д���뷨����ʱ�䲻д��������
//���뷨����˼�룺�� ��Ϊֻ��һ����������������ģ�Ȼ��Ӻ���Ķ��Ԫ�����������һ��Ԫ����ǰ����������� һ��һ���ıȽ�
//���ǰ����������бȸղ��ó���Ԫ�ش���С�������򣩣���ǰ����������д��������һ��λ�ã�ֱ���ҵ�һ�����ȸղ��ó�����С��ͣ��
void insertSort01(int *array,int lengtg)
{
	if (NULL == array)
	{
		return;
	}
	int i = 0, j = 0;
	int tempValue = 0; // �ӵ�һ����ʼ��ֵ ��Ϊһ��Ԫ���������
	for (i = 1; i < lengtg;i++)
	{
		tempValue = array[i];
		j = i - 1;
		while (j >= 0 && (array[j]>tempValue))
		{			
			array[j + 1] = array[j];
			j--;
		}
		if (j!=i-1)
		{
			array[j + 1] = tempValue;
		}
	}

	
}
void insertSort02(int  array[],int length)
{
	if (NULL == array)
	{
		cout << "wrong" << endl;
	}
	int i = 0, j = 0;
	int temp = 0;
	for (i = 1; i < length;i++)
	{
		temp = array[i];
		for (j = i - 1; j >= 0;j--)//���ղ��ó������ݸ�ǰ����������жԱȣ�ǰ������������Ǵ� i-1 �� 0 ������� �Ѿ��źõ�
		{
			if (array[j]>temp)//������������������һ�� //ע ����ط�֮ǰ����˴��� ���� bug ����һ����Сʱ (�ѩn��)b  д���� array[j>temp]  �� >temp Ҳ��������������
			{
				array[j + 1] = array[j];//�߽����⣺�����һ�ε������ʱ�� array[j+1] �Ǹ�array[i] ��ȵ� �����ڶ������
			}
			else // �ҵ��˲���temp С�ĵط�
			{
				break;
			}
		}
		array[j + 1] = temp;
		//coutArray(array,length);
	}
}
//��ϰ
void fuxi(int * array,int length)
{
	if (NULL == array)
	{
		cout<<" param error" << __FILE__ << __FUNCTION__ << __LINE__ << endl;
		return;
	}
	int i = 0, j = 0;

	for (i = 0; i < length;i++)
	{
		int temp = array[i];
		for (j = i-1; j >=0;j--)
		{
			if (array[j]>temp)
			{
				array[j + 1] = array[j];
			}
			else
			{
				break;
			}
		}
		array[j + 1] = temp;
	}
}
int main01(int args,char*argus[])
{
	int array[] = { 32, 15, 1, 5, 87, 10, 96, 54, 3, 8, 45, 6 };
	int length = sizeof(array) / sizeof(array[0]);
	//insertSort(array, length);
	//insertSort01(array, length);
	insertSort02(array, length);
	coutArray(array, length);

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
