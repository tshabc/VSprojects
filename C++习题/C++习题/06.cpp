#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class Goods
{
public:
	Goods(int goodNumber, int buyWeight);
	~Goods();
	static int get_Total_weight()
	{
		return Total_weight;
	}
	int getWeight()
	{
		return weight;
	}
	int getNumber()
	{
		return number;
	}
	Goods * next;
private:
	int number;
	int  weight;
	static  int Total_weight;
};
int Goods::Total_weight = 0;
Goods::Goods(int goodNumber, int buyWeight)
{
	number = goodNumber;
	weight = buyWeight;
	Total_weight += buyWeight;
}

Goods::~Goods()
{
	Total_weight -= weight;
	cout << "余货总重为： " << Total_weight << endl;
}
//买入函数
void purchase(Goods *& head, int num, int w)
{
	Goods *p = new Goods(num, w);
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
	cout << "余货总重为： " << Goods::get_Total_weight() << endl;
}

void sale(Goods *&head, int goodNumber)
{
	if (NULL == head)
	{
		cout << "当前商品缺货。" << endl;
	}
	Goods*p = head;
	Goods*q = p;
	if (head->getNumber() == goodNumber)
	{
		head = head->next;
		delete p;
	}
	else
	{
		for (p; p != NULL; q = p, p = p->next)
		{
			if (p->getNumber() == goodNumber)
			{
				q->next = p->next;
				delete p;
				p = NULL;
				break;
			}
		}
	}
}
int main06(int args, char*argus[])
{
	Goods* head;
	head = NULL;
	int w, choice, goodNum;
	do 
	{
		cout << "Please choice::" << endl;
		cout << "Key in 1 is purchase\nKey in 2 is sale\nKey in 0 is over.\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			{
				cout << "Please input goodNumber" << endl;
				cin >> goodNum;
				cout << "Please input goodWeight" << endl;
				cin >> w;
				purchase(head, goodNum, w);
			}
			break;
		case 2:
			{
				 cout << "Please input goodNumber" << endl;
				 cin >> goodNum;
				 sale(head, goodNum);
			}
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (choice);
	cout << "Hello World" << endl;
	system("pause");
	return 0;
}
