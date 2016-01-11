#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class planeBase
{
public:
	planeBase();
	~planeBase();
	virtual	int getPower() = 0;
private:

};

planeBase::planeBase()
{
}

planeBase::~planeBase()
{
}

class planeNew:public planeBase
{
public:
	planeNew(int p);
	~planeNew();

	int getPower()
	{
		return power;
	}
	void setPower(int p)
	{
		this->power = p;
	}
	int power;
private:

};

planeNew::planeNew(int p)
{
	this->power = p;
}

planeNew::~planeNew()
{
}

class enemy
{
public:
	enemy(int p);
	~enemy();
	int getPower()
	{
		return power;
	}
	void setPower(int p)
	{
		this->power = p;
	}
	int power;
private:

};

enemy::enemy(int p)
{
	this->power = p;
}

enemy::~enemy()
{
}


void stage(planeBase * p,enemy * e)
{
	if (p->getPower()>e->getPower())
	{
		cout << "我方胜利" << endl;
	}
	else if (p->getPower() < e->getPower())
	{
		cout << "敌方胜利" << endl;
	}
	else
	{
		cout << "平手" << endl;
	}
}

int main(int args,char*argus[])
{

	planeNew p(20);
	enemy e1(10);
	stage(&p, &e1);

	system("pause");
	return 0;
}
