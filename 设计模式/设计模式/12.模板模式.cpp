#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util_tools.h"
using namespace std;
/*
ģ��ģʽ:�ڳ��������� ͳһ�������裬���涨�ýӿڣ�������ʵ�ֽӿڣ����� ���԰Ѹ��� ���� �Ĳ�����������
*/
class makecar
{
public:
	virtual void makeHead() = 0; 
	virtual void makeBody() = 0;
	virtual void makeTail() = 0;
public:
	void make() //ģ�庯�� �����Ǹ����Ѿ�����õ�
	{
		makeHead();
		makeBody();
		makeTail();
	}

protected:
private:
};

class  Jeep:public makecar
{
public:
	virtual void makeHead()
	{
		cout << "������ͷ" << endl;
	}
	virtual void makeBody()
	{
		cout << "��������" << endl;
	}
	virtual void makeTail()
	{
		cout << "������β" << endl;
	}

protected:
private:
};


int main12(int args,char*argus[])
{
	makecar * m = new Jeep;
	m->make();
	SAFE_DEL(m);
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
