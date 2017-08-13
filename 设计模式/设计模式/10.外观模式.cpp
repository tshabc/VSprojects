#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util_tools.h"
using namespace std;
//外观模式 
/*
	用一个大系统 将小系统包裹起来，让用户使用这个大系统，降低耦合度
*/
class SubSystemA
{
public:
	void doThing()
	{
		cout << "A" << endl;
	}
protected:
private:
};

class SubSystemB
{
public:
	void doThing()
	{
		cout << "B" << endl;
	}
protected:
private:
};

class SubSystemC
{
public:
	void doThing()
	{
		cout << "C" << endl;
	}
protected:
private:
};

//耦合度高的做法
void ogao()
{
	SubSystemA * sysA = new SubSystemA;
	SubSystemB * sysB = new SubSystemB;
	SubSystemC * sysC = new SubSystemC;
	sysA->doThing();
	sysB->doThing();
	sysC->doThing();
}

/*
耦合度低的做法 ，做一层封装
*/
class fade
{
public:
	fade()
	{
		sysA = new SubSystemA;
		sysB = new SubSystemB;
		sysC = new SubSystemC;
	}
	~fade()
	{
		SAFE_DEL(sysA);
		SAFE_DEL(sysB);
		SAFE_DEL(sysC);
	}
	void fDoThing()
	{
		cout << "外观 封闭使用 " << endl;
		sysA->doThing();
		sysB->doThing();
		sysC->doThing();
	}
private:
	SubSystemA * sysA;
	SubSystemB * sysB;
	SubSystemC * sysC;
};


void oDi()
{
	fade * mf = new fade;
	mf->fDoThing();
	SAFE_DEL(mf);

}

int main10(int args,char*argus[])
{
	ogao();
	oDi();
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
