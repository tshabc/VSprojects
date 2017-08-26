#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string> // c++ 进行了操作符重载，带点h的都是C的，没有重载操作符
#include "util_tools.h"
using namespace std;

/*
状态模式：（状态机的实现）
	通过 用户的状态改变用户的行为
两部分：
	一、 状态类					 basestate 基类
	二、 根据状态执行行为的对象  worker 工人 要保存自己当前的状态 
*/

// 工人的状态区分
enum workerEnum 
{
	Enum_none = 0,//无
	Enum_sixh = 1,//起床了
	Enum_senh = 2,//吃早餐
	Enum_eigh = 3,//上班去
};

class worker;
class baseState
{
public:
	virtual void doSomething(worker* w) = 0;;
protected:
private:
};

class worker
{
public:
	worker();
	~worker();
public:
	void setCurState(baseState* bs)
	{
		if (bs)
		{
			state = bs;
		}
	}
	baseState* getCurState()
	{
		return state;
	}
	void setCurEnum(workerEnum we)
	{
		this->we = we;
	}
	workerEnum getCurEnum()
	{
		return we;
	}
	void goTodoSomething()
	{
		state->doSomething(this);
	}
public:
	workerEnum we;
	baseState* state;
};


class  state1:public baseState
{
public:
	virtual void doSomething(worker* w);
protected:
private:
	
};

class  state2 :public baseState
{
public:
	virtual void doSomething(worker* w);
protected:
private:
};


class  state3 :public baseState
{
public:
	virtual void doSomething(worker* w);
	
protected:
private:
};

void state1:: doSomething(worker* w)
{
	if (w->getCurEnum() == Enum_sixh)
	{
		cout << "起床了" << endl;
	}
	else if (w->getCurEnum() == Enum_senh)
	{
		delete(w->getCurState());
		w->setCurEnum(Enum_senh);
		w->setCurState(new state2);
		w->getCurState()->doSomething(w);
	}
	else if (w->getCurEnum() == Enum_eigh)
	{
		delete(w->getCurState());
		w->setCurEnum(Enum_eigh);
		w->setCurState(new state3);
		w->getCurState()->doSomething(w);
	}
	else
	{
		delete w->getCurState();
		w->setCurEnum(Enum_none);
	}

}
void state2::doSomething(worker* w)
{
	if (w->getCurEnum() == Enum_senh)
	{
		cout << "吃早餐" << endl;
	}
	else if (w->getCurEnum() == Enum_sixh)
	{
		delete(w->getCurState());
		w->setCurEnum(Enum_sixh);
		w->setCurState(new state1);
		w->getCurState()->doSomething(w);
	}
	else if (w->getCurEnum() == Enum_eigh)
	{
		delete(w->getCurState());
		w->setCurEnum(Enum_eigh);
		w->setCurState(new state3);
		w->getCurState()->doSomething(w);
	}
	else
	{
		delete w->getCurState();
		w->setCurEnum(Enum_none);
	}
}
void state3::doSomething(worker* w)
{
	if (w->getCurEnum() == Enum_eigh)
	{
		cout << "上班去" << endl;
	}
	else if (w->getCurEnum() == Enum_sixh)
	{
		delete(w->getCurState());
		w->setCurEnum(Enum_sixh);
		w->setCurState(new state1);
		w->getCurState()->doSomething(w);
	}
	else if (w->getCurEnum() == Enum_senh)
	{
		delete(w->getCurState());
		w->setCurEnum(Enum_senh);
		w->setCurState(new state2);
		w->getCurState()->doSomething(w);
	}
	else
	{
		delete w->getCurState();
		w->setCurEnum(Enum_none);
	}
}

worker::worker()
{
	//注意类的声明顺序 会影响编译 放到state1 后面
	state = new state1; //设置默认状态 为 状态 一
}
worker::~worker()
{
	SAFE_DEL(state);
}
int main(int args,char*argus[])
{
	worker * m_work = new worker;
	m_work->setCurEnum(Enum_senh);
	m_work->goTodoSomething();

	cout<<"Hello World"<<endl;

	system("pause");
	return 0;
}



