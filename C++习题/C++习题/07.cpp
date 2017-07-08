#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
class caleulator
{
public:
	caleulator();
	~caleulator();
	void operator++();
	void operator--();
private:
	int value;
};

caleulator::caleulator()
{
	value = 0;
}

caleulator::~caleulator()
{
}
void caleulator::operator++()
{
	if (value<65535)
	{
		value++;
	}
	else
	{
		cout << "Data overflow" << endl;
		//abort();
	}
	
}
void caleulator::operator--()
{
	if (value > 0)
	{
		value--;
	}
	else
	{
		cout << "Data overflow" << endl;
		//abort();
	}

}
class test
{
public:
	test();
	~test();

private:
	int a;
	static int b;

};
int test::b = 10;
test::test()
{
}

test::~test()
{
}
int main07(int args,char*argus[])
{
	caleulator counter;
	for (int i = 0; i < 10;i++)
	{
		counter++;
	}
	for (int i = 10; i > 0;i--)
	{
		counter--;
	}
	cout << "sizeof(test) = " << sizeof(test) << endl; //静态变量跟其它成员变量不在一个地方
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
