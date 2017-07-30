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
			cout << "进来了" << endl;
			s =  new siglation;
		}
		return s;
	}
	void boss()
	{
		cout << "只有一个boss" << endl;
	}
	void freeInstace()
	{
		if (s != NULL)
		{
			delete s;
			s = NULL;
			cout << "释放了" << endl;
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

	// _beginthread(myhandler, 0, NULL); // 创建线程


	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
