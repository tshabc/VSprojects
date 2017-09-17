#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string> // c++ 进行了操作符重载，带点h的都是C的，没有重载操作符
#include "util_tools.h"
using namespace std;
/*
迭代器模式：
	用自己的语法实现了STL类型的 iterator

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

//迭代器
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
	virtual void first() // 第一个元素
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

//集合
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
		cout << "内存分配失败" << endl;
		return -1;
	}
	contreteIterator* contr = new contreteIterator(my);
	if (!contr)
	{
		cout << "内存分配失败" << endl;
		return -1;
	}
	contr->first(); // 初始化索引 也可以在构造函数里面初始化一遍，不过有这个函数会更灵活
	while (!contr->isdone())
	{
		cout << contr->currentItem() << endl;
		contr->next();
	}

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
