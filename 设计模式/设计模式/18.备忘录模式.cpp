#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "util_tools.h"
using namespace std;
/*
����¼ģʽ��
���������ڲ�״̬��������Ҫ��ʱ��ָ���������ǰ��״̬
�����ڣ��������� ctrl + z
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
		cout << "�����ǣ�"<<m_name << endl;
		return m_name;
	}
	int getAge( )
	{
		cout << "�����ǣ�" << m_age << endl;
		return m_age;
	}
	//����һ������¼ ���Լ��ĸ�����
	memery* getMemry()
	{
		return new memery(m_age,m_name);
	}
	// ��ԭ�Լ�����ǰ��״̬ ��� �ط� Ҫע�� ��� ��char* ֮��ģ����� ���������ǳ���� ������
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
	cout << "���л�ԭ" << endl;
	p18->setMemry(m_me);
	p18->getAge();
	SAFE_DEL(p18);
	SAFE_DEL(m_me);

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
