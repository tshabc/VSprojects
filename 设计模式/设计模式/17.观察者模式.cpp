#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <list>
#include "util_tools.h"
using namespace std;
/*
�۲���ģʽ��
	��������һ�Զ�Ĺ�ϵ ��ʹ��ÿһ������ı�״̬�����������������ǵĶ��� ��õ�֪ͨ��
	���еĹ۲��߶����ڵȴ�֪ͨ�����������յ�֪ͨ
������
	�ʼ�֪ͨ
	���͵�֪ͨ
	����
*/


// �ȴ���Ϣ�Ĺ۲��� ����
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

//������Ϣ��֪ͨ��

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

//ʵ�� �۲��� 1
class  createObserver :public BaseObsever
{
public:
	virtual void update(string stat)
	{
		m_state = stat;
		cout << "����״̬��" << m_state << endl;
	}
protected:
private:
	string m_state;
};
//ʵ�� �۲��� 2
class  createObserver2 :public BaseObsever
{
public:
	virtual void update(string stat)
	{
		m_state = stat;
		cout << "����״̬��" << m_state << endl;
	}
protected:
private:
	string m_state;
};


int main17(int args, char*argus[])
{
	BaseNotify * ntify = new notifiyer;
	BaseObsever* bob   = new createObserver;
	ntify->attatchObsever(bob); // �ѹ۲��߼��뵽�ȴ�֪ͨ�б� 
	ntify->sendNotify("�յ��ʼ�֪ͨ");

	SAFE_DEL(ntify);
	SAFE_DEL(bob);

	cout << "Hello World" << endl;
	system("pause");
	return 0;
}
