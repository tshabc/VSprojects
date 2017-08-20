#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util_tools.h"
#include <list>
using namespace std;
/*
�н���ģʽ��
	������ �࣬���н������뿪�������
������
	���� ͨ�� �н� ���ҹ�˾ �ϰ�
*/

class condetios // ��������� ���� ����
{
public:
	condetios(int h, int s)
	{
		salary = h;
		skills = s;
	}
	~condetios()
	{

	}
	virtual bool getGoal(condetios* co) = 0;
	virtual int getSalary() = 0;
	virtual int getSkills() = 0;
	int salary;
	int skills;
private:
};


class agency // �н��� Ӧ����������Ա�� ѡ������
{
public:
	agency()
	{

	}
	~agency()
	{

	}
	void setPerson(condetios* pconditios)
	{
		m_person = pconditios;
	}
	void setCompony(condetios* comp)
	{
		m_compoey = comp;
	}
	bool toMakeGoal()
	{
		if (m_person && m_compoey)
		{
			if (m_person->getSalary() == m_compoey->getSalary() && m_person->getSkills() == m_compoey->getSkills())
			{
				cout << "ƥ��ɹ�" << endl;
				return true;
			}
		}
		cout << "ƥ��ʧ��" << endl;
		return false;
	}
protected:
private:
	condetios * m_person; // һ���˵ļ���
	condetios * m_compoey;// һ����˾�ļ���
	//���Ҫ��չ�Ļ������� ��������б� ���� 
// 	std::list<condetios*> m_personList;
// 	std::list<condetios*> m_compneyList;
};


class onePerson :public condetios// ����
{
public:
	onePerson(int h, int s,agency* ag) :condetios(h, s)
	{
		hopeSalary = h;
		haveSkills = s;
		m_ag = ag;
	}
	~onePerson()
	{

	}
	int getSalary()
	{
		return hopeSalary;
	}
	int getSkills()
	{
		return haveSkills;
	}
	virtual bool getGoal(condetios* co)
	{
		/*
		�Լ���

		if (co)
		{
			if (co->getSalary() == hopeSalary && co->getSkills() == haveSkills)
			{
				cout << "��˾����ƥ��" << endl;
				return true;
			}
		}
		cout << "��˾������ƥ��" << endl;
		return false;*/
		
		//ͨ���н���
		m_ag->setCompony(co);
		m_ag->setPerson(this);
		return m_ag->toMakeGoal();

	}

protected:
private:
	int hopeSalary;
	int haveSkills;
	agency* m_ag; // ÿ����Ӧ���и���Ƹ��վ���ʺ�
};

class compony :public condetios// ��˾
{

public:
	compony(int sa, int s,agency* ag) :condetios(sa, s)
	{
		salary = sa;
		skills = s;
		m_ag = ag;
	}
	~compony()
	{

	}
	int getSalary()
	{
		return salary;
	}
	int getSkills()
	{
		return skills;
	}
	virtual bool getGoal(condetios* co)
	{
		/*
		�Լ���
		
		if (co)
		{
			if (co->getSalary() == salary && co->getSkills() == skills)
			{
				cout << "��Ա����ƥ��" << endl;
				return true;
			}
		}
		cout << "��Ա������ƥ��" << endl;
		return false;*/

		// ͨ���н� ��
		m_ag->setCompony(this);
		m_ag->setPerson(co);
		return m_ag->toMakeGoal();

	}
protected:
private:
	int salary;//�ܸ�����н��
	int skills;//��Ҫ����
	agency* m_ag; // ÿ����˾Ӧ���и���Ƹ��վ���ʺ�
};

int main16(int args,char*argus[])
{
	agency * ag = new agency;
	condetios* oneP = new onePerson(10000, 1, ag);
	condetios* comp = new compony(10000, 1, ag);
	oneP->getGoal(comp);
	comp->getGoal(oneP);


/*
	ag->setCompony(comp);
	ag->setPerson(oneP);
	ag->toMakeGoal();*/

	SAFE_DEL(comp);
	SAFE_DEL(oneP);
	SAFE_DEL(ag);

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
