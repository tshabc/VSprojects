#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <list>
#include "util_tools.h"
using namespace std;
/*
命令模式 
	将一个请求封装为一个对象，从而使你可用不同的请求对客户端进行参数化，对请求排队或记录请求日志，以及支持可撤销的操作
事例：
	医院里面的挂号看病模式
	医生可以实现看不同病的请求
	前台护士可以实现 挂号 排队功能 
*/
//功能类
class doctor
{
public:
	void treat_eye()
	{
		cout << "看眼睛" << endl;
	}
	void treat_nose()
	{
		cout << "看鼻子" << endl;
	}


protected:
private:
};
//对命令进行抽象
class commond
{
public:
	virtual void treat() = 0;
protected:
private:
};

//命令类 
class commondTreadEye:public commond
{
public:
	commondTreadEye(doctor * dod)
	{

		m_doctor = dod;
	}

	void treat()
	{
		m_doctor->treat_eye();// 不同的命令
	}
protected:
private:
	doctor* m_doctor;
};
//命令类
class commondTreadNose:public commond
{
public:
	commondTreadNose(doctor * dod)
	{

		m_doctor = dod;
	}	
	void treat()
	{
		m_doctor->treat_nose(); // 不同的命令
	}

protected:
private:
	doctor* m_doctor;
};
// 前台护士
class nurse
{
public:
	nurse(commond* cm)
	{
		m_comm = cm;
	}

	void submitCase() // 下达命令
	{
		m_comm->treat();
	}
protected:
private:
	commond * m_comm;

};
//为达到排队的效果再做一个护士长类
//护士长有一个命令列表
class headnurse
{
public:
	headnurse()
	{
		m_commondList.clear();
	}
	~headnurse()
	{
		if (!m_commondList.empty())
		{
			std::list<commond*>::iterator it = m_commondList.begin();
			for (it; it != m_commondList.end();++it)
			{
				SAFE_DEL(*it);
			}
		}
		m_commondList.clear();
	}
	void insertCommond(commond* cmd)
	{
		m_commondList.push_back(cmd);
	}
	void submitCaseList()
	{
		std::list<commond*>::iterator it = m_commondList.begin();
		for (it; it != m_commondList.end(); ++it)
		{
			(*it)->treat();
		}
	}
protected:
private:
	std::list<commond*> m_commondList;

};


//测试程序
void test01()
{
	doctor * mdoc = new doctor;
	commondTreadNose* cmn = new commondTreadNose(mdoc);
	cmn->treat();

	SAFE_DEL(cmn);
	SAFE_DEL(mdoc);

}
void test02()
{
	doctor * mdoc = new doctor;
	commond* cm = new commondTreadEye(mdoc);// 可以产生不同的命令
	nurse* nur = new nurse(cm); // 护士有了不同的命令可以产生不同的效果
	nur->submitCase();

	SAFE_DEL(nur);
	SAFE_DEL(cm);
	SAFE_DEL(mdoc);

}
void test03()
{
	doctor * mdoc = new doctor;
	commond* cm1 = new commondTreadEye(mdoc);// 可以产生不同的命令
	commond* cm2 = new commondTreadNose(mdoc);// 可以产生不同的命令
	headnurse* hn = new headnurse;
	hn->insertCommond(cm1);
	hn->insertCommond(cm2);
	hn->submitCaseList();

	SAFE_DEL(hn);
	SAFE_DEL(mdoc);

}
int main13(int args,char*argus[])
{
// 	test01();
// 	test02();

	test03();

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
