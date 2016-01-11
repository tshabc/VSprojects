#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class teacher
{
public:
	teacher(char *name,int age);
	teacher(const teacher &t);
	teacher();
	~teacher();
	void operator= (teacher &t)
	{
		if (this->name != NULL)
		{
			free(this->name);
		}
		this->age = t.age;
		this->name = (char *)malloc(20);
		if (this->name == NULL)
		{
			cout << "get memory failed " << endl;
			return ;
		}
		memset(this->name, 0, 20);
		strcpy(this->name, t.name);
	}
	void setName(char * name);
	char* getName();
	void setAge(int age);
	int getAge();
	static int mystatic;
	static void mysStaticFun()
	{
		cout << mystatic << endl;
	}
private:
	int age;
	char *name;
};
int teacher::mystatic = 0;
teacher::teacher(char *name, int age)
{
	if (name == NULL)
	{
		cout << "construct error " << endl;
		return;
	}
	this->age = age;
	this->name = (char *)malloc(20);
	memset(this->name, 0, 20);
	strcpy(this->name, name);
}
teacher::teacher()
{
	this->name = NULL;
	this->age = 0;
}

teacher::~teacher()
{
	if (this->name != NULL)
	{
		free(this->name);
		this->name = NULL;
	}
}

teacher::teacher(const teacher &t)
{
	this->name = (char *)malloc(20);
	if (this->name != NULL)
	{
		free(this->name);
	}
	this->age = t.age;
	this->name = (char *)malloc(20);
	if (this->name == NULL)
	{
		cout << "get memory failed " << endl;
		return;
	}
	memset(this->name, 0, 20);
	strcpy(this->name, t.name); 

	//以下行数专门测试 第四种应用场景 testConstr04()
	cout << "进入赋值构造函数" << endl;
}
void teacher::setName(char * newname)
{
	if (newname == NULL)
	{
		return;
	}
	if (this->name!= NULL)
	{
		free(this->name);
	}
	this->name = new char[20];
	strcpy(this->name, newname);
}
char* teacher::getName()
{
	return this->name;
}
void teacher::setAge(int newage)
{
	this->age = newage;
}
int teacher::getAge()
{
	return this->age;
}

teacher tesCopyCostr04()
{
	//返回一个对象 生成匿名对象  第四种应用场景
	teacher temp("tempteatcher",20);
	return temp;

}

void testCopyConstr()
{
	teacher t1("wanglaoshi",30);
	teacher t2 = t1;
	teacher t3;
	t3 = t2;
	t2 = t1;
	teacher t4 = tesCopyCostr04();
}
void aboutNewDelete()
{
	{
		// 关于 new delete delete[]

		teacher *t = new teacher("teacher A ", 20); //如果带 （） 就要调用此类的 构造函数
		cout << t->getName() << endl;
		teacher *t2 = new teacher;
		teacher *t3 = new teacher[5];
		t3[0].setAge(20);
		t3[1].setName("newTeacher");
		delete t;
		delete[] t3;
	}
}

void aboutMallocFree()
{
	{
		// 和 malloc free()
		teacher *a = (teacher*)malloc(sizeof(teacher));
		a->setAge(20);
		//a->setName("tA"); // 用 malloc 申请的内存不会自己调用自己的构造函数 当进入 setName() 内 释放内存会报错
		free(a);
	}
}
int main02(int args, char*argus[])
{
	testCopyConstr();
	// Malloc 跟 new 都不会自动释放内存 需要自己手动释放
	aboutNewDelete();
	aboutMallocFree();
	teacher::mysStaticFun();
	system("pause");
	return 0;
}
