#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
/*
	ԭ��ģʽ�������Լ�Ϊģ�ͣ��ٽ���һ���µ��Լ�
	��Ӧ�����о���Ҫע�� ���ǳ����
	
*/

class person
{
public:
	person(){}
	virtual ~person(){}
public:
	virtual person* clone() = 0;
	virtual void printt() = 0;
protected:
private:
};

class CPP :public person
{
public:
	CPP(){}
	CPP(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
	CPP(string name, int age,char * cmputer)
	{
		this->name = name;
		this->age = age;
		if (cmputer)
		{
			this->computer = cmputer;
		}
	}
	~CPP()
	{
		if (this->computer)
		{
			free(this->computer);
			this->computer = NULL;
		}
		cout << "����" << endl;
	};
	
public:

	virtual person* clone()
	{
		CPP* cp = new CPP;
		/*cp->name = name;
		cp->age = age;*/

		*cp = *this;//���������ǳ����
		//�������
		if (this->computer)
		{
			cout << "�ֽ��� = " << sizeof(this->computer) << endl;;
			cout << "�ֽ���strlen = " << (strlen(computer)+1) << endl;;
			cp->computer = (char*)malloc(strlen(computer) + 1);
			strcpy(cp->computer, this->computer);
		}
		return cp;
	}
	virtual void printt()
	{
		cout << name.c_str() << endl;
		cout << age << endl;
		cout << computer << endl;
	}
protected:
private:
	string name;
	int age;
	char  *computer;
};

int main05(int args,char*argus[])
{
	char * computer = (char *)malloc(256);
	
	if (!computer)
	{
		cout << "�ڴ����ʧ��" << endl;
		return -1;
	}
	cout << computer << "\n"<<endl;
	cout << "�ֽ��� = " << sizeof(computer) << endl;;
	CPP* cp = new CPP("testName", 1,computer);
	person* clonecp = cp->clone();
	clonecp->printt();

	delete clonecp;//�ͷŸ����ָ��ʱһ��Ҫע�� ��������������� virtual ��  �������ܵ���������������������ͷ�
	delete cp;
	
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
