#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util_tools.h"
using namespace std;
/*
模板模式:在抽象类里面 统一操作步骤，并规定好接口，让子类实现接口，这样 可以把各个 具体 的操作步骤解耦合
*/
class makecar
{
public:
	virtual void makeHead() = 0; 
	virtual void makeBody() = 0;
	virtual void makeTail() = 0;
public:
	void make() //模板函数 流程是父类已经定义好的
	{
		makeHead();
		makeBody();
		makeTail();
	}

protected:
private:
};

class  Jeep:public makecar
{
public:
	virtual void makeHead()
	{
		cout << "制作车头" << endl;
	}
	virtual void makeBody()
	{
		cout << "制作车身" << endl;
	}
	virtual void makeTail()
	{
		cout << "制作车尾" << endl;
	}

protected:
private:
};


int main12(int args,char*argus[])
{
	makecar * m = new Jeep;
	m->make();
	SAFE_DEL(m);
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
