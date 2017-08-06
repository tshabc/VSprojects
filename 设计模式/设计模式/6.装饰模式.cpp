#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
//װ��ģʽ Ŀ�� �ǶԻ�����й�����ǿ �ӹ��� ���Խ����������
//�ؼ�����Ƶ����ڣ������ʱ��ע��һ������ָ�룬�˻���ָ�� �������κ��������࣬�����Ϳ�������ϵ�ʱ��ʵ�ֶ�̬������ʵ�ֶ��ֹ��ܵ���ǿ���
  
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
		cout << "������" << endl;
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
		cout << "������Ӿ" << endl;
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
	flycar(car * ca); //��̬����
	~flycar();
	void fly()
	{
		cout << "���Է�" << endl;
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
