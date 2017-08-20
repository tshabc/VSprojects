#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util_tools.h"
#include <list>
using namespace std;
/*
中介者模式：
	将两个 类，用中介来隔离开，解耦合
事例：
	个人 通过 中介 来找公司 上班
*/

class condetios // 互相满足的 基类 条件
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


class agency // 中介者 应该有两方人员的 选择条件
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
				cout << "匹配成功" << endl;
				return true;
			}
		}
		cout << "匹配失败" << endl;
		return false;
	}
protected:
private:
	condetios * m_person; // 一个人的简历
	condetios * m_compoey;// 一个公司的简历
	//如果要扩展的话，可以 存放两个列表 如下 
// 	std::list<condetios*> m_personList;
// 	std::list<condetios*> m_compneyList;
};


class onePerson :public condetios// 个人
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
		自己找

		if (co)
		{
			if (co->getSalary() == hopeSalary && co->getSkills() == haveSkills)
			{
				cout << "公司条件匹配" << endl;
				return true;
			}
		}
		cout << "公司条件不匹配" << endl;
		return false;*/
		
		//通过中介找
		m_ag->setCompony(co);
		m_ag->setPerson(this);
		return m_ag->toMakeGoal();

	}

protected:
private:
	int hopeSalary;
	int haveSkills;
	agency* m_ag; // 每个人应该有个招聘网站的帐号
};

class compony :public condetios// 公司
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
		自己找
		
		if (co)
		{
			if (co->getSalary() == salary && co->getSkills() == skills)
			{
				cout << "人员条件匹配" << endl;
				return true;
			}
		}
		cout << "人员条件不匹配" << endl;
		return false;*/

		// 通过中介 找
		m_ag->setCompony(this);
		m_ag->setPerson(co);
		return m_ag->toMakeGoal();

	}
protected:
private:
	int salary;//能给出的薪资
	int skills;//需要技能
	agency* m_ag; // 每个公司应该有个招聘网站的帐号
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
