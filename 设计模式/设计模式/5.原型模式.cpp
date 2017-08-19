#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
/*
	原型模式就是以自己为模型，再建造一个新的自己
	反应到类中就需要注意 深拷贝浅拷贝
	
*/

class person
{
public:
	person(){}
	virtual ~person(){}
public:
	virtual person* clone() = 0;
	virtual void printt() = 0;
protected:
private:
};

class CPP :public person
{
public:
	CPP(){}
	CPP(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
	CPP(string name, int age,char * cmputer)
	{
		this->name = name;
		this->age = age;
		if (cmputer)
		{
			this->computer = cmputer;
		}
	}
	~CPP()
	{
		if (this->computer)
		{
			free(this->computer);
			this->computer = NULL;
		}
		cout << "析构" << endl;
	};
	
public:

	virtual person* clone()
	{
		CPP* cp = new CPP;
		/*cp->name = name;
		cp->age = age;*/

		*cp = *this;//这个操作是浅拷贝
		//深拷贝如下
		if (this->computer)
		{
			cout << "字节数 = " << sizeof(this->computer) << endl;;
			cout << "字节数strlen = " << (strlen(computer)+1) << endl;;
			cp->computer = (char*)malloc(strlen(computer) + 1);
			strcpy(cp->computer, this->computer);
		}
		return cp;
	}
	virtual void printt()
	{
		cout << name.c_str() << endl;
		cout << age << endl;
		cout << computer << endl;
	}
protected:
private:
	string name;
	int age;
	char  *computer;
};

int main05(int args,char*argus[])
{
	char * computer = (char *)malloc(256);
	
	if (!computer)
	{
		cout << "内存分配失败" << endl;
		return -1;
	}
	cout << computer << "\n"<<endl;
	cout << "字节数 = " << sizeof(computer) << endl;;
	CPP* cp = new CPP("testName", 1,computer);
	person* clonecp = cp->clone();
	clonecp->printt();

	delete clonecp;//释放父类的指针时一定要注意 父类的析构函数是 virtual 的  这样才能调用子类的析构函数进行释放
	delete cp;
	
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
