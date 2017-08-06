#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
/*
	建造者模式 思想是将一个产品分成多个部分 
	由一个设计师指挥 一支施工队进行建造
	施工队可以有多种 每个施工队都能建造自己擅长风格的产品 （所以这里要有一个施工队的基类）
	设计师里面有一个基类的指针  给设计师一个不同的队伍，设计师就能指挥他们建造不同的建筑
	施工队建造完成 后给返回一个产品

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
class buider // 工程队
{
public:
	virtual void buildWall() = 0;
	virtual void buildDoor() = 0;
	virtual void buildFloor() = 0;
	virtual void buildWindow() = 0;
	virtual House* getHouse() = 0;
};
//公寓工程队
class FlatBuider:public buider
{
public:
	FlatBuider();
	~FlatBuider();
	virtual void buildWall()
	{
		m_house->setWall("建造公寓墙");
	}
	virtual void buildDoor()
	{
		m_house->setDoor("建造公寓门");
	}
	virtual void buildFloor()
	{
		m_house->setfloor("建造公寓地板");
	}
	virtual void buildWindow()
	{
		m_house->setWindow("建造公寓窗户");
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

//别墅工程队
class VillaBuider:public buider
{
public:
	VillaBuider();
	~VillaBuider();
	virtual void buildWall()
	{
		m_house->setWall("建造别墅墙");
	}
	virtual void buildDoor()
	{
		m_house->setDoor("建造别墅门");
	}
	virtual void buildFloor()
	{
		m_house->setfloor("建造别墅地板");
	}
	virtual void buildWindow()
	{
		m_house->setWindow("建造别墅窗户");
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
//设计师 需要用到建筑队
class Designer
{
public:
	Designer(buider* build); //多态产生在这里
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
