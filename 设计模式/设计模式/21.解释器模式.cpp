#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string> // c++ �����˲��������أ�����h�Ķ���C�ģ�û�����ز�����
#include "util_tools.h"
using namespace std;
/*
������ģʽ��
	�����ڲ���ģʽ��ֻ������ ��һ��������м�״̬ �洢����������
*/

class context
{
public:
	context()
	{
	}

	~context()
	{
	}
	
	int getNum() const { return num; }
	void setNum(int val) { num = val; }
	int getRes() const { return res; }
	void setRes(int val) { res = val; }
private:
	int num;
	int res;
};
//������ ����
class expression
{
public:
	virtual void interpretor(context* con) = 0;
protected:
private:
};
// plus

class plusExpresion:public expression
{
public:
	virtual void interpretor(context* con)
	{
		if (con)
		{
			int num = con->getNum();
			num++;
			con->setNum(num);
			con->setRes(num);
		}
	}
protected:
private:
};

// minus
class minusExpresion:public expression
{
public:
	virtual void interpretor(context* con)
	{
		if (con)
		{
			int num = con->getNum();
			num--;
			con->setNum(num);
			con->setRes(num);
		}

	}
protected:
private:
};


int main(int args,char*argus[])
{
	context*	m_con = NULL;
	expression* m_exp = NULL;

	m_con = new context;
	m_exp = new plusExpresion;

	m_con->setNum(10);
	m_exp->interpretor(m_con);
	cout << m_con->getNum() << endl;

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
