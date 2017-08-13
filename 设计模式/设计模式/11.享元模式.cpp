#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include "util_tools.h"
#include <string>
#include <string.h>// 跟上面那个不一样，有区别
using namespace std;
/*
如果 一个对象 在某个使用过程 中被使用了很多次，那么有必要对这个对象进行 单一创建，用于共享
以共享的方式，支持大量的颗粒度很细的对象 ，避免重复使用
*/

class Person
{
public:
	Person(string name,int age)
	{
		this->age = age;
		this->name = name;
	}

	virtual void gotoClassroom() = 0;
protected:
	int age;
	string name;
private:
};
class Teacher:public Person
{
public:
	Teacher(string name, int age,int id) :Person( name,  age)
	{
		tId = id;
	}
	virtual void gotoClassroom()
	{
		cout << "让"<<name.c_str()<<"老师去上课" << endl;
	}
protected:
private:
	int tId;
};
class teacherFactory
{
public:
	~teacherFactory()
	{
		std::map<int, Teacher*>::iterator it = teacherList.begin();
		for (it; it != teacherList.end();++it)
		{
			SAFE_DEL(it->second);
		}
	}


public:
	Person* getTeacher(int  id)
	{
		std::map<int, Teacher*>::iterator it = teacherList.find(id);
		if (it != teacherList.end())
		{
			return it->second;
		}
		else
		{
			string sname;
			int aage;
			cout << "请输入 老师姓名" << endl;
			//scanf("%s", sname);
			//getline(cin, sname);
			cin >> sname;
			cout << "请输入 老师年龄" << endl;
			cin >> aage;
			Teacher* nt = new Teacher(sname, aage, id);
			if (nt)
			{
				teacherList.insert(make_pair(id, nt));
			}
			else
			{
				SAFE_DEL(nt);
			}
			return nt;
		}

	}
protected:
private:
	std::map<int, Teacher*> teacherList;
};
int main(int args,char*argus[])
{
	teacherFactory * tf = new teacherFactory;
	Person* t1 = NULL;
	Person* t2 = NULL;
	Person* t3 = NULL;
	t1 = tf->getTeacher(001);
	t2 = tf->getTeacher(002);
	t3 = tf->getTeacher(001);
	t1->gotoClassroom();
	t2->gotoClassroom();
	t3->gotoClassroom();
	SAFE_DEL(tf);

	t1 = NULL;
	t2 = NULL;
	t3 = NULL;
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
