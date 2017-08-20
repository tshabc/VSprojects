#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util_tools.h"
using namespace std;
/*
策略模式：
	不同的策略共有一个基类，策略的使用都有一个基类的指针（多态用的），给它不同的子类，
	使用者就能调用不同的策略实现不同的任务
*/

class baseMethod
{
public:
	virtual void playMusic() = 0;
protected:
private:
};

class earphones:public baseMethod
{
public:
	virtual void playMusic()
	{
		cout << "use earphones to play" << endl;
	}
protected:
private:
};

class soundBox :public baseMethod
{
public:
	virtual void playMusic()
	{
		cout << "use soundBox to play" << endl;
	}
protected:
private:
};
class singer
{
public:
	singer(baseMethod* method)
	{
		m_method = method; 
	}
	~singer()
	{

	}
	void selfPlayer()
	{
		m_method->playMusic();
	}
protected:
private:
	baseMethod* m_method;

};

int main15(int args,char*argus[])
{
	baseMethod* souB = new soundBox;

	singer* p = new singer(souB);
	p->selfPlayer();

	SAFE_DEL(p);
	SAFE_DEL(souB);

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
