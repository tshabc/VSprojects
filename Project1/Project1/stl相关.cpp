#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;

void diguishan(vector<int> &vt,int num) //普通遍历实现
{

	vector<int>::iterator it;
	
	for (it = vt.begin(); it < vt.end(); )
	{
		if (*it == 13)
		{
			it = vt.erase(it);
			//num--;			
		}
		else
		{
			++it;
		}
	}
}
void diguishan01(vector<int> &vt, int num) //递归实现
{
	if (num <= 0 )
	{
		return;
	}
	vector<int>::iterator it;

	for (it = vt.begin(); it < vt.end();it++)
	{
		if (*it == 13)
		{
			vt.erase(it);
			num--;			
			break;
		}
	}
	diguishan(vt, num);
}

int x = 1;
//题1
void fun1()
{
	if (1==x)
	{
		int x = 2;
	}
	cout << "x!" << x << endl;
}
void printstr(const char *s)
{
	cout << "second" << s << endl;
}
void fun2()
{
	string s1 = "abc";
	string s2 = "def";

	if (const char *s =(s1+s2).c_str())
	{
		cout << (s1 + s2).c_str() << endl;
		cout << "first:" << s << endl;
	}
	printstr((s1 + s2).c_str());
}

void fun4()
{
	char p1[] = "abc";
	p1[0] = 'd';
	char *p2 = p1;
	p2[1] = 'e';
	cout << "p1:" << p1 << endl;
	cout << "p2:" << p2<< endl;
	char *p3 = "abc"; //只读常量
	p3[0] = 'd';	  // 去修改常量 一改就错 无法修改
	cout << "p3" << p3 << endl;
}
char * mystrcpy( char*buff, char*source)
{
	int ret = 0;
	if (buff == NULL||source == NULL)
	{
		return NULL;
	}
	char *p = buff;
	char *q = source;
	cout << (*p++ = *q++) << endl;
	while ((*q) != '\0')  // while((*p++ = *q++) != '\0')
	{
		*(p++) = *(q++);
	}
	return buff;
}

class A
{
public:
	A()
	{
		m_nSize = 10;
		m_pData = (char*)malloc(m_nSize);
		memset(m_pData, 0, m_nSize);
		mystrcpy(m_pData, "abcdef");
	}
	A(const A & a)
	{
		if (this->m_pData != NULL)
		{
			free(this->m_pData);
			this->m_pData = NULL;
		}
		this->m_pData = (char*)malloc(a.m_nSize);
		strcpy((char *)this->m_pData, (char*)a.m_pData);
		this->m_nSize = a.m_nSize;
	}
	A& operator= (A &a)
	{
		if (this->m_pData != NULL)
		{
			free(this->m_pData);
			this->m_pData = NULL;
		}
		this->m_pData = (char*)malloc(a.m_nSize);
		strcpy((char *)this->m_pData, (char*)a.m_pData);
		this->m_nSize = a.m_nSize;
		return *this;
	}
public:
	char*   m_pData;
	int 	m_nSize;
};
class B: A
{
public:
	B();
	~B();
	virtual void fun2()
	{
		cout << "自身的" << endl;
	}
private:

};

B::B()
{
}

B::~B()
{
}
void vectorTest()
{

	vector< int> vt(5);
	vt[0] = 1;
	vt[1] = 13;
	vt[2] = 13;
	vt[3] = 1;
	vt[4] = 13;
	int num = 0;
	int i;
	vector< int>::iterator it;
	for (i = 0, it = vt.begin(); it != vt.end(); i++, it++)
	{
		cout << (*it) << endl;
		if (*it == 13)
		{
			num++;
		}
		cout << "vt.at(i) = " << vt.at(i) << endl;
	}

	diguishan01(vt, num);
	cout << "删除之后" << endl;
	for (it = vt.begin(); it < vt.end(); it++)
	{
		cout << (*it) << endl;
	}
}
void stackeTest()
{
	stack <int> st;
	for (int i = 0; i < 9;i++)
	{
		st.push(i + 1);
	}
	while (!st.empty())
	{
		int temp = st.top();
		cout << "stack  " << temp << endl;
		st.pop();
	}
}
int main03(int args,char*argus[])
{

	fun1();
	fun2();
	//fun4();
	char *p = (char *)1000;
	int n = (int)(p + 100);
	cout << n << endl;
	{
		int *p = (int *)1000;
		int n = (int)(p + 100);
		cout << n << endl;
	}
	{
		char *p = new char[4];
		p[0] = 1;
		p[1] = 2;
		p[2] = 3;
		p[3] = 4;
		int * pInt = (int *)p;
		int n = *pInt;
		printf("%x \n", n);

	}
	{
		char buff[1024] = { 0 };
		mystrcpy(buff, "asdfasdf");

	}
	{
		A a;
		A b;

		a = b;
		A c = b;
	}
	{
		B b;
		//b.m_nSize; // 140 行继承时不写继承方式，默认以private 私有方式继承
		b.fun2();
	}

	{
		stackeTest();
	}

	system("pause");

	return 0;
}
