#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util_tools.h"

using namespace std;

//桥接模式， 实例 汽车  安装  发动机     ，  图形  渲染  颜色
/*
汽车 （不同的汽车 抽象化）
发动机（不同的发动机 抽象化）
汽车中有个发动机的 成员（虚基类，多态用）， 调用 此成员实现 发动机的安装  （此过程称为桥接）


*/
class baseengine
{
public:
	virtual ~baseengine()
	{

	}
	virtual void installEngine() = 0;
protected:
private:
};

class  basecar
{
public:
	virtual ~basecar()
	{

	}
	basecar(baseengine* engine)
	{
		this->m_baseEngine = engine;
	}
	virtual void carinstallEngine() = 0;
protected:
	baseengine* m_baseEngine;
private:
};
// 不同的车型
class carbmw: public basecar
{
public:
	carbmw(baseengine*bengine) :basecar(bengine)
	{

	}
	virtual void carinstallEngine()
	{
		cout << "汽车厂的安装发动机业务 " << endl;
		m_baseEngine->installEngine();
	}
protected:
private:
};
class carbenz : public basecar
{
public:
	carbenz(baseengine*bengine) :basecar(bengine)
	{

	}
	virtual void carinstallEngine()
	{
		cout << "汽车厂的安装发动机业务 " << endl;
		m_baseEngine->installEngine();
	}
protected:
private:
};
// 不同的发动机 型号
class engine2000:public baseengine
{
public:
	virtual void installEngine()
	{
		cout << "发动机的技术团队进行专业安装完成" << endl;
	}
protected:
private:
};
class engine2008 :public baseengine
{
public:
	virtual void installEngine()
	{
		cout << "发动机的技术团队进行专业安装完成" << endl;
	}
protected:
private:
};

int main(int args,char*argus[])
{
	baseengine* eng2000 = new engine2000;
	basecar * bmw = new carbmw(eng2000);
	bmw->carinstallEngine();

	SAFE_DEL(bmw);
	SAFE_DEL(eng2000);

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
