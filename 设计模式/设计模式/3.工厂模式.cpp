#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
enum ENUME_Fruits
{
	ENUM_banana,
	ENUM_apple,		
};

class fruitObj    
{
public:
	fruitObj();
	~fruitObj();
	virtual void giveName() ; //纯虚函数 加 =0 这样可以没有函数体，如果不加 = 0 就要有函数体
	virtual void eat() = 0; //抽象类必须在子类中重写
private:

};

fruitObj::fruitObj()
{
}

fruitObj::~fruitObj()
{
}

void fruitObj::giveName()
{
	
}
class banana :public fruitObj
{
public:
	banana();
	~banana();
	virtual void giveName();
	virtual void eat();
private:

};

banana::banana()
{
}

banana::~banana()
{
}
void banana::giveName()
{
	cout << "我是香蕉" << endl;
}
void banana::eat()
{
	cout << "把香蕉吃了" << endl;
}
class factory
{
public:
	factory();
	~factory();
	fruitObj* creatFruit(ENUME_Fruits f);
private:

};

factory::factory()
{
}

factory::~factory()
{
}
fruitObj* factory::creatFruit(ENUME_Fruits f)
{
	fruitObj * fruit = NULL;
	switch (f)
	{
	case ENUM_banana:
		return new banana;
		break;
	case ENUM_apple:
		break;
	default:
		break;
	}

}
int main(int args,char*argus[])
{
	factory* fa = new factory;
	fruitObj* fruit = NULL;
	fruit = fa->creatFruit(ENUM_banana);
	fruit->giveName();
	fruit->eat();
	if (fa)
	{
		delete fa;
		fa = NULL;
	}
	if (fruit)
	{
		delete fruit;
		fruit = NULL;
	}
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
