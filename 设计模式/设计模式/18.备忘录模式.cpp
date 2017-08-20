#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "util_tools.h"
using namespace std;
/*
备忘录模式：
保存对象的内部状态，并在需要的时候恢复到对象以前的状态
类似于，撤销操作 ctrl + z
*/
class memery
{
public:
	memery(int age, string name)
	{
		m_age = age;
		m_name = name;
	}
	~memery()
	{

	}

public:
	void setName(string sname)
	{
		m_name = sname;
	}
	void setAge(int ag)
	{
		m_age = ag;
	}
	string getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}
private:
	int m_age;
	string m_name;

};


class person18
{
public:
	person18(int age, string name);
	~person18();
	void setName(string sname)
	{
		m_name = sname;
	}
	void setAge(int ag)
	{
		m_age = ag;
	}
	string getName( )
	{
		cout << "名字是："<<m_name << endl;
		return m_name;
	}
	int getAge( )
	{
		cout << "年龄是：" << m_age << endl;
		return m_age;
	}
	//创建一个备忘录 （自己的副本）
	memery* getMemry()
	{
		return new memery(m_age,m_name);
	}
	// 还原自己到以前的状态 这个 地方 要注意 如果 有char* 之类的，可能 存在深拷贝跟浅拷贝 的问题
	void setMemry(memery* old)
	{
		if (old)
		{
			m_age = old->getAge();
			m_name = old->getName();
		}
	}

private:
	int m_age;
	string m_name;
};

person18::person18(int age,string name)
{
	m_age = age;
	m_name = name;

}

person18::~person18()
{
}



int main18(int args,char*argus[])
{
	person18  * p18 = new person18(18, "me");
	memery* m_me = p18->getMemry();

	p18->setAge(19);
	p18->getAge();
	cout << "进行还原" << endl;
	p18->setMemry(m_me);
	p18->getAge();
	SAFE_DEL(p18);
	SAFE_DEL(m_me);

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
