#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
/*
	������ģʽ ˼���ǽ�һ����Ʒ�ֳɶ������ 
	��һ�����ʦָ�� һ֧ʩ���ӽ��н���
	ʩ���ӿ����ж��� ÿ��ʩ���Ӷ��ܽ����Լ��ó����Ĳ�Ʒ ����������Ҫ��һ��ʩ���ӵĻ��ࣩ
	���ʦ������һ�������ָ��  �����ʦһ����ͬ�Ķ��飬���ʦ����ָ�����ǽ��첻ͬ�Ľ���
	ʩ���ӽ������ �������һ����Ʒ

*/

class House
{
public:
	House();
	~House();
	void setDoor(string door)
	{
		this->door = door;
	}
	void setfloor(string floor)
	{
		this->floor_ = floor;
	}
	void setWindow(string window)
	{
		this->window = window;
	}
	void setWall(string w)
	{
		this->wall = w;
	}
	string getDoor()
	{
		cout << (this->door).c_str() << endl;
		return this->door;
	}
	string getfloor()
	{
		cout << (this->floor_).c_str() << endl;
		return this->floor_;
	}
	string getWindow()
	{
		cout << (this->window).c_str() << endl;
		return this->window;
	}
	string getWall()
	{
		cout << (this->wall).c_str() << endl;
		return this->wall;
	}
private:
	string door;
	string floor_;
	string window;
	string wall;
};

House::House()
{
}

House::~House()
{
}
class buider // ���̶�
{
public:
	virtual void buildWall() = 0;
	virtual void buildDoor() = 0;
	virtual void buildFloor() = 0;
	virtual void buildWindow() = 0;
	virtual House* getHouse() = 0;
};
//��Ԣ���̶�
class FlatBuider:public buider
{
public:
	FlatBuider();
	~FlatBuider();
	virtual void buildWall()
	{
		m_house->setWall("���칫Ԣǽ");
	}
	virtual void buildDoor()
	{
		m_house->setDoor("���칫Ԣ��");
	}
	virtual void buildFloor()
	{
		m_house->setfloor("���칫Ԣ�ذ�");
	}
	virtual void buildWindow()
	{
		m_house->setWindow("���칫Ԣ����");
	}
	virtual House* getHouse()
	{
		return m_house;
	}
private:
	House* m_house;
};

FlatBuider::FlatBuider()
{
	m_house = new House;
}

FlatBuider::~FlatBuider()
{
	
}

//�������̶�
class VillaBuider:public buider
{
public:
	VillaBuider();
	~VillaBuider();
	virtual void buildWall()
	{
		m_house->setWall("�������ǽ");
	}
	virtual void buildDoor()
	{
		m_house->setDoor("���������");
	}
	virtual void buildFloor()
	{
		m_house->setfloor("��������ذ�");
	}
	virtual void buildWindow()
	{
		m_house->setWindow("�����������");
	}
	virtual House* getHouse()
	{
		return m_house;
	}
private:
	House* m_house;
private:

};

VillaBuider::VillaBuider()
{
	m_house = new House;
}

VillaBuider::~VillaBuider()
{
	if (m_house)
	{
		delete m_house;
		m_house = NULL;
	}
}
//���ʦ ��Ҫ�õ�������
class Designer
{
public:
	Designer(buider* build); //��̬����������
	~Designer();
	void constructor()
	{
		m_build->buildWall();
		m_build->buildWindow();
		m_build->buildDoor();
	}
private:
	buider * m_build;
};

Designer::Designer(buider* build)
{
	m_build = build;
}

Designer::~Designer()
{
	
}
int main04(int args,char*argus[])
{
	Designer* ds = NULL;
	House*   bu = NULL;
	FlatBuider* fl = NULL;
	fl = new FlatBuider;
	ds = new Designer(fl);
	ds->constructor();
	bu = fl->getHouse();
	bu->getDoor();
	bu->getWall();
	bu->getWindow();
	if (fl)
	{
		delete fl;
		fl = NULL;
	}
	if (bu)
	{
		delete bu;
		bu = NULL;
	}
	
	if (ds)
	{
		delete ds;
		ds = NULL;
	}
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
