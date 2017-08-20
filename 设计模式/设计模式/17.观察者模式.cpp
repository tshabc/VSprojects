#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <list>
#include "util_tools.h"
using namespace std;
/*
观察者模式：
	定义对象间一对多的关系 ，使得每一个对象改变状态，则所有依赖于他们的对象都 会得到通知。
	所有的观察者对象在等待通知，其他对象收到通知
事例：
	邮件通知
	博客的通知
	侦听
*/


// 等待消息的观察者 基类
class BaseObsever
{
public:
	BaseObsever()
	{

	}
	virtual ~BaseObsever()
	{

	}
	virtual void update(string stat) = 0;
protected:
private:
};

//发送消息的通知人

class BaseNotify
{
public:
	virtual void attatchObsever(BaseObsever* obs) = 0;
	virtual void detatchObsever(BaseObsever* obs) = 0;
	virtual void sendNotify(string notice) = 0;
protected:
	std::list<BaseObsever*> m_list;
private:
};

class notifiyer :public BaseNotify
{
public:
	virtual void attatchObsever(BaseObsever* obs)
	{
		if (obs)
		{
			m_list.push_back(obs);
		}
	}
	virtual void detatchObsever(BaseObsever* obs)
	{
		if (obs)
		{
			delete obs;
			m_list.remove(obs);
		}
	}
	virtual void sendNotify(string notice)
	{
		std::list<BaseObsever*>::iterator it = m_list.begin();
		for (; it != m_list.end();++it)
		{
			(*it)->update(notice);
		}
	}

protected:
private:
};

//实体 观察者 1
class  createObserver :public BaseObsever
{
public:
	virtual void update(string stat)
	{
		m_state = stat;
		cout << "最新状态：" << m_state << endl;
	}
protected:
private:
	string m_state;
};
//实体 观察者 2
class  createObserver2 :public BaseObsever
{
public:
	virtual void update(string stat)
	{
		m_state = stat;
		cout << "最新状态：" << m_state << endl;
	}
protected:
private:
	string m_state;
};


int main17(int args, char*argus[])
{
	BaseNotify * ntify = new notifiyer;
	BaseObsever* bob   = new createObserver;
	ntify->attatchObsever(bob); // 把观察者加入到等待通知列表 
	ntify->sendNotify("收到邮件通知");

	SAFE_DEL(ntify);
	SAFE_DEL(bob);

	cout << "Hello World" << endl;
	system("pause");
	return 0;
}
