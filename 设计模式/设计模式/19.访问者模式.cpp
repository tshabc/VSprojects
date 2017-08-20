#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string> // c++ 进行了操作符重载，带点h的都是C的，没有重载操作符
#include <list>
#include "util_tools.h"
using namespace std;
/*
访问者模式：
	不同的访问者可以 访问 一个类，并产生不同的效果
事例：
	不同的人去  公园 ：
				清洁工  打扫卫生
				卖票员	卖票
				领导	视察
				市民	休闲
								产生了不同的效果
*/

//访问者类型
enum Evisitor 
{
	Enum_visit_cleaner = 1,
	Enum_visit_citizen = 2,
	Enum_visit_lader   = 3,
};


class BasePark;
//访问者 基类
class baseVisitor
{
public:
	baseVisitor(Evisitor type)
	{
		this->type = type;
	}
public:
	virtual void visitor(BasePark* p) = 0; //访问公园 具体做什么不知道 多态
	Evisitor type;
};


//被访问者 基类
class BasePark
{
public:
	virtual void accept(baseVisitor* bv) = 0;
	virtual	string getname() = 0;
protected:
private:
};

// 访问者实体类
class cleaner :public baseVisitor
{
public:
	cleaner(Evisitor en) :baseVisitor(en)
	{
		this->type = en;
	}
	virtual void visitor(BasePark* p)
	{
		cout << "有些清洁工打扫了 ： " << p->getname() << endl;
	}
	Evisitor type;
};
//市民访问者
class citizen:public baseVisitor
{
public:
	citizen(Evisitor en) :baseVisitor(en)
	{
		this->type = en;
	}
	virtual void visitor(BasePark* p)
	{
		cout << "公园里来了一些市民游玩" << endl;
	}
	Evisitor type;
};
//访问者 领导
class vLader :public baseVisitor
{
public:
	vLader(Evisitor en) :baseVisitor(en)
	{
		this->type = en;
	}
	virtual void visitor(BasePark* p)
	{
		cout << "领导在视察：" << endl;
		cout << p->getname() << endl;
	}
	Evisitor type;
};

//公园实体类 公园A 区 
class newParkA:public BasePark
{
public:
	newParkA(string partname)
	{
		m_partName = partname;
	}
public:
	virtual void accept(baseVisitor* bv)
	{
		bv->visitor(this);
	}
	string getname()
	{
		return m_partName;

	}
	string m_partName;
};

// 公园 B 区
class newParkB :public BasePark
{
public:
	newParkB(string partname)
	{
		m_partName = partname;
	}
public:
	virtual void accept(baseVisitor* bv)
	{
		bv->visitor(this);
	}
	string getname()
	{
		return m_partName;

	}
	string m_partName;
};

// 整个公园 里面有所有园区的列表
class wholePark : public BasePark
{
public:
	wholePark(string partname)
	{
		m_partName = partname;
	}
	virtual void accept(baseVisitor* bv) //
	{
		//判断权限 如果这是领导，那么他就可以访问公园的所有园区
		if (bv->type == Enum_visit_lader)
		{
			std::list<BasePark*>::iterator it = m_visitList.begin();
			for (it; it != m_visitList.end();++it)
			{
				(*it)->accept(bv);
			}
		}
	}

	string getname()
	{
		return m_partName;

	}
	void AddPardComponet(BasePark* pcom)
	{
		m_visitList.push_back(pcom);
	}
public:
	std::list<BasePark*> m_visitList;
	string m_partName;
};

int main(int args,char*argus[])
{
	baseVisitor* visit = new cleaner(Enum_visit_cleaner);
	BasePark * bp = new newParkA("公园A区");
	bp->accept(visit);

	/************************************************************************/
	/* 分割线                                                               */
	/************************************************************************/

	BasePark* bpB = new newParkB("公园B区");

	baseVisitor* lader = new vLader(Enum_visit_lader);
	wholePark * whoP = new wholePark("森林公园");
	whoP->AddPardComponet(bp);
	whoP->AddPardComponet(bpB);
	
	whoP->accept(lader); //公园里面来了 领导


	SAFE_DEL(visit);
	SAFE_DEL(bp);
	SAFE_DEL(bpB);
	SAFE_DEL(lader);
	SAFE_DEL(whoP);


	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
