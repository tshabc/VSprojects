#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <process.h>

using namespace std;

class  siglation
{
public:
	static siglation* getinstance()
	{
		if (NULL == s)
		{
			cout << "������" << endl;
			s =  new siglation;
		}
		return s;
	}
	void boss()
	{
		cout << "ֻ��һ��boss" << endl;
	}
	void freeInstace()
	{
		if (s != NULL)
		{
			delete s;
			s = NULL;
			cout << "�ͷ���" << endl;
		}
	}
private:
	siglation()
	{

	}
	static siglation * s;
};
 siglation* siglation::s = NULL;

 void myhandler(void *)
 {
	
 }

int main01(int args,char*argus[])
{

	siglation* mys = siglation::getinstance();
	mys->boss();
	mys->freeInstace();

	// _beginthread(myhandler, 0, NULL); // �����߳�


	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
