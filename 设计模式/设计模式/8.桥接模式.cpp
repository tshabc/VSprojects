#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util_tools.h"

using namespace std;

//�Ž�ģʽ�� ʵ�� ����  ��װ  ������     ��  ͼ��  ��Ⱦ  ��ɫ
/*
���� ����ͬ������ ���󻯣�
����������ͬ�ķ����� ���󻯣�
�������и��������� ��Ա������࣬��̬�ã��� ���� �˳�Աʵ�� �������İ�װ  ���˹��̳�Ϊ�Žӣ�


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
// ��ͬ�ĳ���
class carbmw: public basecar
{
public:
	carbmw(baseengine*bengine) :basecar(bengine)
	{

	}
	virtual void carinstallEngine()
	{
		cout << "�������İ�װ������ҵ�� " << endl;
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
		cout << "�������İ�װ������ҵ�� " << endl;
		m_baseEngine->installEngine();
	}
protected:
private:
};
// ��ͬ�ķ����� �ͺ�
class engine2000:public baseengine
{
public:
	virtual void installEngine()
	{
		cout << "�������ļ����Ŷӽ���רҵ��װ���" << endl;
	}
protected:
private:
};
class engine2008 :public baseengine
{
public:
	virtual void installEngine()
	{
		cout << "�������ļ����Ŷӽ���רҵ��װ���" << endl;
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
