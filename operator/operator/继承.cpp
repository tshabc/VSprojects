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
		cout << "���࿽�����캯��" << endl;
	}
private:

};

A::A()
{
	cout << "���๹�캯��" << endl;
}

A::~A()
{
	cout << "������������" << endl;
}

class B :public A
{
public:
	B();
	~B();
	B(const B &b)
	{
		cout << "���࿽�����캯��" << endl;
	}
private:

};

B::B()
{
	cout << "���๹�캯��" << endl;
}

B::~B()
{
	cout << "���������캯��" << endl;

}

int main02(int args,char*argus[])
{
	A testa;
	B testB;
	A a = testB; //����������ʼ���������ʱ ������ø���Ŀ������캯��


	system("pause");
	return 0;
}
