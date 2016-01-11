#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class A
{
public:
	A();
	~A();
	A(const A &a)
	{
		cout << "父类拷贝构造函数" << endl;
	}
private:

};

A::A()
{
	cout << "父类构造函数" << endl;
}

A::~A()
{
	cout << "父类析构函数" << endl;
}

class B :public A
{
public:
	B();
	~B();
	B(const B &b)
	{
		cout << "子类拷贝构造函数" << endl;
	}
private:

};

B::B()
{
	cout << "子类构造函数" << endl;
}

B::~B()
{
	cout << "子类析构造函数" << endl;

}

int main02(int args,char*argus[])
{
	A testa;
	B testB;
	A a = testB; //用子类对象初始化父类对象时 ，会调用父类的拷贝构造函数


	system("pause");
	return 0;
}
