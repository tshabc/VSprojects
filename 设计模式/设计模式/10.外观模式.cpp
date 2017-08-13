#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util_tools.h"
using namespace std;
//���ģʽ 
/*
	��һ����ϵͳ ��Сϵͳ�������������û�ʹ�������ϵͳ��������϶�
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

//��϶ȸߵ�����
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
��϶ȵ͵����� ����һ���װ
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
		cout << "��� ���ʹ�� " << endl;
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
