#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util_tools.h"
using namespace std;
//适配器 将一个类的接口转换成另一个类的接口
// 电源适配器 思想 

class MyClass
{
public:
	virtual void use18Vpower() = 0;

private:

};
class _220Vpower
{
public:
	_220Vpower();
	~_220Vpower();
	void use220Vpower()
	{
		cout << "使用220V的电压" << endl;
	}
private:

};
_220Vpower::_220Vpower()
{
}

_220Vpower::~_220Vpower()
{
}


class Adeptor:public MyClass
{
public:
	Adeptor();
	Adeptor(_220Vpower* _220v);
	~Adeptor();
	virtual void use18Vpower()
	{
		m_220v->use220Vpower();
		cout << "适配器 内部进行转换" << endl;
	}
private:
	_220Vpower * m_220v;
};

Adeptor::Adeptor()
{
}
Adeptor::Adeptor(_220Vpower* _220v)
{
	m_220v = _220v;
}

Adeptor::~Adeptor()
{
}



int main07(int args, char*argus[])
{
	_220Vpower * _220v = NULL;
	Adeptor*	 _adp = NULL;
	_220v = new _220Vpower;
	_adp = new Adeptor(_220v);
	_adp->use18Vpower();
	SAFE_DEL(_adp);
	SAFE_DEL(_220v);
	cout << "Hello World" << endl;
	system("pause");
	return 0;
}
