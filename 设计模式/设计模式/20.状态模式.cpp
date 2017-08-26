#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string> // c++ �����˲��������أ�����h�Ķ���C�ģ�û�����ز�����
#include "util_tools.h"
using namespace std;

/*
״̬ģʽ����״̬����ʵ�֣�
	ͨ�� �û���״̬�ı��û�����Ϊ
�����֣�
	һ�� ״̬��					 basestate ����
	���� ����״ִ̬����Ϊ�Ķ���  worker ���� Ҫ�����Լ���ǰ��״̬ 
*/

// ���˵�״̬����
enum workerEnum 
{
	Enum_none = 0,//��
	Enum_sixh = 1,//����
	Enum_senh = 2,//�����
	Enum_eigh = 3,//�ϰ�ȥ
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
		cout << "����" << endl;
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
		cout << "�����" << endl;
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
		cout << "�ϰ�ȥ" << endl;
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
	//ע���������˳�� ��Ӱ����� �ŵ�state1 ����
	state = new state1; //����Ĭ��״̬ Ϊ ״̬ һ
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



