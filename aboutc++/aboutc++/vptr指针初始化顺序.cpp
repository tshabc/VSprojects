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
		cout << "������������" << endl;
	}
	virtual void print()
	{
		cout << "����" << endl;
	}
	virtual void print01()
	{
		cout << "����01" << endl;
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
		cout << "����" << endl;
	}
private:

};

child::child()
{
}


child::~child()
{
	cout << "������������" << endl;

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
