#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
//注入 控制反转
class protocol
{
public:
	protocol();
	virtual ~protocol();
	virtual int testProtocol() = 0;
private:
	
};

protocol::protocol()
{
}

protocol::~protocol()
{
}

class factory:public protocol
{
public:
	factory();
	~factory();
	virtual int testProtocol();
private:

};

factory::factory()
{
}

factory::~factory()
{
}
 int factory::testProtocol()
{
	 cout << "factory thing factory do!" << endl;
	 return 0;
}
 class business
 {
 public:
	 business();
	 ~business();
	 void setf(factory*f)
	 {
		 if (NULL == f)
		 {
			 cout << "目标为空" << __FILE__ << __LINE__ << endl;
		 }
		 this->f = f;
	 }
	 int doBusiness();
	 int doBusiness(factory* f);
 private:
	 factory * f;
 };

 business::business()
 {
 }

 business::~business()
 {
 }
 int business::doBusiness()
 {
	 int ret = 0;
	 f->testProtocol();
	 return ret;
 }
 int business::doBusiness(factory* f)
 {
	if (NULL == f)
	{
		cout << "目标为空" << __FILE__ << __LINE__ << endl;
	}
	f->testProtocol();
	return 0;
 }
int main08(int args,char*argus[])
{
	factory *f = new factory;
	business myBusiness;
	myBusiness.setf(f);
	myBusiness.doBusiness();
	myBusiness.doBusiness(f);
	unsigned int a = 8;
	int b = -7;
	if (a + b <=5)
	{
		printf("x\n");
	}
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
