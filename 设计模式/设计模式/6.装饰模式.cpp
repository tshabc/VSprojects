#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
//装饰模式 目的 是对基类进行功能增强 加功能 可以进行自由组合
//关键的设计点是在：构造的时候注入一个基类指针，此基类指针 可以是任何他的子类，这样就可以在组合的时候实现多态，进而实现多种功能的增强组合
  
class car
{
public:
	virtual void show() = 0;
private:

};

class runcar :public car
{
public:
	runcar();
	~runcar();
	virtual void show()
	{
		cout << "可以跑" << endl;
	}
private:

};

runcar::runcar()
{
}

runcar::~runcar()
{
}
class swimcar:public car
{
public:
	
	swimcar(car* car1)
	{
		m_car = car1;
	}
	~swimcar();
	void swim()
	{
		cout << "可以游泳" << endl;
	}
	virtual void show()
	{
		swim();
		m_car->show();
	}
private:
	car* m_car;
};

swimcar::~swimcar()
{
}

class flycar:public car
{
public:
	flycar(car * ca); //多态产生
	~flycar();
	void fly()
	{
		cout << "可以飞" << endl;
	}
	virtual void show()
	{
		fly();
		m_car->show();
	}
private:
	car* m_car;
};

flycar::flycar(car * c)
{
	m_car = c;
}

flycar::~flycar()
{
}
int main(int args,char*argus[])
{
	car* ca = NULL;
	ca = new runcar;
	ca->show();
	cout << "------------------------" << endl;
	swimcar* swc = new swimcar(ca);
	swc->show();

	cout << "------------------------" << endl;

	flycar* fl = new flycar(swc);
	fl->show();

	cout << "------------------------" << endl;
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
