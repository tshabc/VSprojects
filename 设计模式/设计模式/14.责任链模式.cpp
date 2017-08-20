#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util_tools.h"
using namespace std;
/*
责任链模式：
	链条式处理流程 ，完成一个，进入下一个流程，一步一步完成产品

*/
class makeCar
{
public:
	virtual void handleCar() = 0;
	makeCar* setNextHandle(makeCar* next)
	{
		m_next = next;
		return m_next;
	}
protected:
	makeCar* m_next;
private:
};
class makeHead:public makeCar
{
public:
	virtual void handleCar()
	{
		cout << "make car head" << endl;
		if (m_next)
		{
			m_next->handleCar();
		}
	}
protected:
private:
};
class makeBody:public makeCar
{
public:
	virtual void handleCar()
	{
		cout << "make car Body" << endl;
		if (m_next)
		{
			m_next->handleCar();
		}
	}
protected:
private:
};
class makeTail : public makeCar
{
public:
	virtual void handleCar()
	{
		cout << "make car tail" << endl;
		if (m_next)
		{
			m_next->handleCar();
		}
	}
protected:
private:
};

int main14(int args,char*argus[])
{
	makeHead* m_head = new makeHead;
	makeBody* m_body = new makeBody;
	makeTail* m_tail = new makeTail;

	/*--------流程设置开始--------*/
	m_head->setNextHandle(m_body);
	m_body->setNextHandle(m_tail);
	m_tail->setNextHandle(NULL);
	/*--------流程设置结束--------*/

	/*--------启动流程--------*/
	m_head->handleCar();



	SAFE_DEL(m_head);
	SAFE_DEL(m_body);
	SAFE_DEL(m_tail);


	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
