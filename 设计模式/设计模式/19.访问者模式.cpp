#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string> // c++ �����˲��������أ�����h�Ķ���C�ģ�û�����ز�����
#include <list>
#include "util_tools.h"
using namespace std;
/*
������ģʽ��
	��ͬ�ķ����߿��� ���� һ���࣬��������ͬ��Ч��
������
	��ͬ����ȥ  ��԰ ��
				��๤  ��ɨ����
				��ƱԱ	��Ʊ
				�쵼	�Ӳ�
				����	����
								�����˲�ͬ��Ч��
*/

//����������
enum Evisitor 
{
	Enum_visit_cleaner = 1,
	Enum_visit_citizen = 2,
	Enum_visit_lader   = 3,
};


class BasePark;
//������ ����
class baseVisitor
{
public:
	baseVisitor(Evisitor type)
	{
		this->type = type;
	}
public:
	virtual void visitor(BasePark* p) = 0; //���ʹ�԰ ������ʲô��֪�� ��̬
	Evisitor type;
};


//�������� ����
class BasePark
{
public:
	virtual void accept(baseVisitor* bv) = 0;
	virtual	string getname() = 0;
protected:
private:
};

// ������ʵ����
class cleaner :public baseVisitor
{
public:
	cleaner(Evisitor en) :baseVisitor(en)
	{
		this->type = en;
	}
	virtual void visitor(BasePark* p)
	{
		cout << "��Щ��๤��ɨ�� �� " << p->getname() << endl;
	}
	Evisitor type;
};
//���������
class citizen:public baseVisitor
{
public:
	citizen(Evisitor en) :baseVisitor(en)
	{
		this->type = en;
	}
	virtual void visitor(BasePark* p)
	{
		cout << "��԰������һЩ��������" << endl;
	}
	Evisitor type;
};
//������ �쵼
class vLader :public baseVisitor
{
public:
	vLader(Evisitor en) :baseVisitor(en)
	{
		this->type = en;
	}
	virtual void visitor(BasePark* p)
	{
		cout << "�쵼���Ӳ죺" << endl;
		cout << p->getname() << endl;
	}
	Evisitor type;
};

//��԰ʵ���� ��԰A �� 
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

// ��԰ B ��
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

// ������԰ ����������԰�����б�
class wholePark : public BasePark
{
public:
	wholePark(string partname)
	{
		m_partName = partname;
	}
	virtual void accept(baseVisitor* bv) //
	{
		//�ж�Ȩ�� ��������쵼����ô���Ϳ��Է��ʹ�԰������԰��
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
	BasePark * bp = new newParkA("��԰A��");
	bp->accept(visit);

	/************************************************************************/
	/* �ָ���                                                               */
	/************************************************************************/

	BasePark* bpB = new newParkB("��԰B��");

	baseVisitor* lader = new vLader(Enum_visit_lader);
	wholePark * whoP = new wholePark("ɭ�ֹ�԰");
	whoP->AddPardComponet(bp);
	whoP->AddPardComponet(bpB);
	
	whoP->accept(lader); //��԰�������� �쵼


	SAFE_DEL(visit);
	SAFE_DEL(bp);
	SAFE_DEL(bpB);
	SAFE_DEL(lader);
	SAFE_DEL(whoP);


	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
