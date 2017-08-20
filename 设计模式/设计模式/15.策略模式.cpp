#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util_tools.h"
using namespace std;
/*
����ģʽ��
	��ͬ�Ĳ��Թ���һ�����࣬���Ե�ʹ�ö���һ�������ָ�루��̬�õģ���������ͬ�����࣬
	ʹ���߾��ܵ��ò�ͬ�Ĳ���ʵ�ֲ�ͬ������
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
