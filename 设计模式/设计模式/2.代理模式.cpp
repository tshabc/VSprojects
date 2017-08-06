// 设计模式.cpp : 定义控制台应用程序的入口点。
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
		cout << "卖书" << endl;
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
		cout << "代理做活动打折了" << endl;
	}
private:
	Subject* m_subject;
};


int _tmain02(int argc, _TCHAR* argv[])
{
	cout << "设计模式 - 代理模式" << endl;
	Subject* s = new dangdang();
	s->sailbook();
	delete s;
	system("pause");
	return 0;
}

