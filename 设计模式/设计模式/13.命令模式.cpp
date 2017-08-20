#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <list>
#include "util_tools.h"
using namespace std;
/*
����ģʽ 
	��һ�������װΪһ�����󣬴Ӷ�ʹ����ò�ͬ������Կͻ��˽��в��������������Ŷӻ��¼������־���Լ�֧�ֿɳ����Ĳ���
������
	ҽԺ����ĹҺſ���ģʽ
	ҽ������ʵ�ֿ���ͬ��������
	ǰ̨��ʿ����ʵ�� �Һ� �Ŷӹ��� 
*/
//������
class doctor
{
public:
	void treat_eye()
	{
		cout << "���۾�" << endl;
	}
	void treat_nose()
	{
		cout << "������" << endl;
	}


protected:
private:
};
//��������г���
class commond
{
public:
	virtual void treat() = 0;
protected:
private:
};

//������ 
class commondTreadEye:public commond
{
public:
	commondTreadEye(doctor * dod)
	{

		m_doctor = dod;
	}

	void treat()
	{
		m_doctor->treat_eye();// ��ͬ������
	}
protected:
private:
	doctor* m_doctor;
};
//������
class commondTreadNose:public commond
{
public:
	commondTreadNose(doctor * dod)
	{

		m_doctor = dod;
	}	
	void treat()
	{
		m_doctor->treat_nose(); // ��ͬ������
	}

protected:
private:
	doctor* m_doctor;
};
// ǰ̨��ʿ
class nurse
{
public:
	nurse(commond* cm)
	{
		m_comm = cm;
	}

	void submitCase() // �´�����
	{
		m_comm->treat();
	}
protected:
private:
	commond * m_comm;

};
//Ϊ�ﵽ�Ŷӵ�Ч������һ����ʿ����
//��ʿ����һ�������б�
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


//���Գ���
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
	commond* cm = new commondTreadEye(mdoc);// ���Բ�����ͬ������
	nurse* nur = new nurse(cm); // ��ʿ���˲�ͬ��������Բ�����ͬ��Ч��
	nur->submitCase();

	SAFE_DEL(nur);
	SAFE_DEL(cm);
	SAFE_DEL(mdoc);

}
void test03()
{
	doctor * mdoc = new doctor;
	commond* cm1 = new commondTreadEye(mdoc);// ���Բ�����ͬ������
	commond* cm2 = new commondTreadNose(mdoc);// ���Բ�����ͬ������
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
