#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
// �򵥹���ֻ�����һ�� ��Ʒ����
// �����Ĺ���ģʽӦ�����һ�� �������� ��һ����Ʒ����  ����������һ����Ʒ��ʱ��Ҫ�� ������
// һ�������� ��Ʒ�Ĺ����̳л��๤������һ���� ��Ʒ��̳в�Ʒ����
enum ENUME_Fruits
{
	ENUM_banana,
	ENUM_apple,		
};

class fruitObj    
{
public:
	fruitObj();
	~fruitObj();
	virtual void giveName() ; //���麯�� �� =0 ��������û�к����壬������� = 0 ��Ҫ�к�����
	virtual void eat() = 0; //�������������������д
private:

};

fruitObj::fruitObj()
{
}

fruitObj::~fruitObj()
{
}

void fruitObj::giveName()
{
	
}
class banana :public fruitObj
{
public:
	banana();
	~banana();
	virtual void giveName();
	virtual void eat();
private:

};

banana::banana()
{
}

banana::~banana()
{
}
void banana::giveName()
{
	cout << "�����㽶" << endl;
}
void banana::eat()
{
	cout << "���㽶����" << endl;
}
class factoryObj
{
public:
	virtual fruitObj* createProduct() = 0;
private:

};
class factoryBanana: public factoryObj
{
public:
	//fruitObj* creatFruit(ENUME_Fruits f);// �򵥹���������ģʽ ������ ��˼����һ��������������ˮ����������ھ�
	virtual fruitObj* createProduct();		//��������������ģʽ���޲Σ�ֻ����һ��ˮ������������ 
private:

};
/* // �򵥹���������ģʽ
fruitObj* factoryBanana::creatFruit(ENUME_Fruits f)
{
	fruitObj * fruit = NULL;
	switch (f)
	{
	case ENUM_banana:
		return new banana;
		break;
	case ENUM_apple:
		break;
	default:
		break;
	}

}*/
// ������������ ÿһ������ֻ����һ�� ��Ʒ�����ֲ�ƷҪ������ֹ���
fruitObj* factoryBanana::createProduct()
{
	return new banana;
}
int main03(int args,char*argus[])
{
/*
	factory* fa = new factory;
	fruitObj* fruit = NULL;
	fruit = fa->creatFruit(ENUM_banana);
	fruit->giveName();
	fruit->eat();*/
	factoryObj* fa = new factoryBanana; //��̬
	fruitObj * banana = fa->createProduct();//��̬
	banana->giveName();
	if (fa)
	{
		delete fa;
		fa = NULL;
	}
	if (banana)
	{
		delete banana;
		banana = NULL;
	}
	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
