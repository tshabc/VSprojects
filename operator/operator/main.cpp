#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class compe
{
public:
	compe(int a, int b);
	~compe();
	void outPut()
	{
		cout << "result = " << x << "+" << y << endl;
	}
	compe(const compe &c)
	{
		this->x = c.x;
		this->y = c.y;
		cout << "调用拷贝构造函数" << endl;
	}
	compe operator/(compe & ctemp)
	{
		compe temp(this->x / ctemp.x, this->y / ctemp.y);
		return temp;
	}

private:
	friend compe add(compe &a, compe &b);
	friend compe operator+ (compe &a, compe &b);
	friend  ostream & operator<<(ostream &out, compe &c);

	int x;
	int y;
};

compe::compe(int a,int b)
{
	this->x = a;
	this->y = b;
}

compe::~compe()
{
}
 compe add(compe &a,compe &b)
{
	compe temp(a.x+b.x,a.y+b.y);



	return temp;
}
 compe operator+ (compe &a, compe &b)
 {
	 compe temp(a.x + b.x, a.y + b.y);
	 return temp;
 }
 ostream & operator<<(ostream &out, compe &c)
 {
	 out << "测试" << endl;
	 return out;
 }

int main01(int args,char*argus[])
{
	compe c1(10,20);
	compe c2 = compe(2,3);
	compe c3 = add(c1,c2); //c1 + c2;
	c3.outPut();
	compe c4 = c1 + c2;
	c4.outPut();
	compe c5 = c1 / c2;
	c5.outPut();
	cout << c5 << c5<<endl;
	system("pause");
	return 0;
}
