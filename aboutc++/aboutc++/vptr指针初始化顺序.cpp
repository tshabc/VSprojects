#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class base
{
public:
	base()
	{

	}
	virtual ~base()
	{
		cout << "父类析构函数" << endl;
	}
	virtual void print()
	{
		cout << "父类" << endl;
	}
	virtual void print01()
	{
		cout << "父类01" << endl;
	}
protected:
private:
};

class child:public base
{
public:
	child();
	~child();
	void print()
	{
		cout << "子类" << endl;
	}
private:

};

child::child()
{
}


child::~child()
{
	cout << "子类析构函数" << endl;

}

void test()
{
/*
	child c;
	c.print();
	c.print01();
	cout << "sizeof(base) = " << sizeof(base) << endl;
	cout << "sizeof(child) = " << sizeof(child) << endl;
*/
/*
	child *c = new child;
	delete c;  
*/

	base *b = new base;
	delete b;

}
int main(int args,char*argus[])
{
	test();
	system("pause");
	return 0;
}
