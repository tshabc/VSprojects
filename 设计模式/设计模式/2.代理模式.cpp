// ���ģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class Subject
{
public:
	virtual void sailbook() = 0;
};

class realSubject:public Subject
{
public:
	virtual void sailbook()
	{
		cout << "����" << endl;
	}
};

class dangdang:public Subject
{
public:
	virtual void sailbook()
	{
		realSubject* r = new realSubject();
		dazhe();
		r->sailbook();

	}
	void dazhe()
	{
		cout << "�������������" << endl;
	}
private:
	Subject* m_subject;
};


int _tmain02(int argc, _TCHAR* argv[])
{
	cout << "���ģʽ - ����ģʽ" << endl;
	Subject* s = new dangdang();
	s->sailbook();
	delete s;
	system("pause");
	return 0;
}

