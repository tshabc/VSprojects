#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util_tools.h"
using namespace std;
//������ ��һ����Ľӿ�ת������һ����Ľӿ�
// ��Դ������ ˼�� 

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
		cout << "ʹ��220V�ĵ�ѹ" << endl;
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
		cout << "������ �ڲ�����ת��" << endl;
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
