#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string> // c++ �����˲��������أ�����h�Ķ���C�ģ�û�����ز�����
#include "util_tools.h"
using namespace std;
/*
������ģʽ��
	���Լ����﷨ʵ����STL���͵� iterator

*/
#define  MSIZE 5
typedef int Object;
class myIterator
{
public:
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isdone() = 0;
	virtual Object currentItem() = 0;
protected:
private:
};

class aggregte
{
public:
	virtual myIterator* createIterator() = 0;
	virtual Object getItem(int index) = 0;
	virtual int getSize() = 0;
	Object obj[MSIZE];
};

//������
class contreteIterator:public myIterator
{
public:
	contreteIterator(aggregte* ag)
	{
		_ag = ag;
	}
	~contreteIterator()
	{
		SAFE_DEL(_ag);
	}
public:
	virtual void first() // ��һ��Ԫ��
	{
		_curIndex = 0;
	}
	virtual void next()
	{
		if (_curIndex<_ag->getSize())
		{
			_curIndex++;
		}
		
	}
	virtual bool isdone()
	{
		return (_curIndex == _ag->getSize());
	}
	virtual Object currentItem()
	{
		return _ag->getItem(_curIndex);
	}
protected:
private:
	int _curIndex;
	aggregte* _ag;
};

//����
class myconcreateAggregte:public aggregte
{
public:
	myconcreateAggregte()
	{
		for (int i = 0; i < MSIZE ; i++)
		{
			obj[i] = i + 100;
		}
	}
	~myconcreateAggregte()
	{

	}
public:
	virtual myIterator* createIterator()
	{
		return new contreteIterator(this);
	}
	virtual Object getItem(int index)
	{
		return obj[index];
	}
	virtual int getSize()
	{
		return MSIZE;
	}
protected:
private:


};




int main(int args,char*argus[])
{
	myconcreateAggregte * my = new myconcreateAggregte();
	if (!my)
	{
		cout << "�ڴ����ʧ��" << endl;
		return -1;
	}
	contreteIterator* contr = new contreteIterator(my);
	if (!contr)
	{
		cout << "�ڴ����ʧ��" << endl;
		return -1;
	}
	contr->first(); // ��ʼ������ Ҳ�����ڹ��캯�������ʼ��һ�飬�������������������
	while (!contr->isdone())
	{
		cout << contr->currentItem() << endl;
		contr->next();
	}

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
