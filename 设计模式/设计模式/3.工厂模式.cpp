#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
// 简单工厂只设计了一个 产品基类
// 真正的工厂模式应该设计一个 工厂基类 加一个产品基类  后来人增加一个产品的时候要加 两个类
// 一个是生产 产品的工厂继承基类工厂，另一个是 产品类继承产品基类
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
class factoryObj
{
public:
	virtual fruitObj* createProduct() = 0;
private:

};
class factoryBanana: public factoryObj
{
public:
	//fruitObj* creatFruit(ENUME_Fruits f);// 简单工厂用这种模式 传参数 ，思想是一个工厂生产多种水果，代码高内聚
	virtual fruitObj* createProduct();		//真正工厂是这种模式，无参，只生产一种水果，代码解耦合 
private:

};
/* // 简单工厂用这种模式
fruitObj* factoryBanana::creatFruit(ENUME_Fruits f)
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

}*/
// 真正工厂如下 每一个工厂只生产一种 产品，多种产品要定义多种工厂
fruitObj* factoryBanana::createProduct()
{
	return new banana;
}
int main03(int args,char*argus[])
{
/*
	factory* fa = new factory;
	fruitObj* fruit = NULL;
	fruit = fa->creatFruit(ENUM_banana);
	fruit->giveName();
	fruit->eat();*/
	factoryObj* fa = new factoryBanana; //多态
	fruitObj * banana = fa->createProduct();//多态
	banana->giveName();
	if (fa)
	{
		delete fa;
		fa = NULL;
	}
	if (banana)
	{
		delete banana;
		banana = NULL;
	}
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
