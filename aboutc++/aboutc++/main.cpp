#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
class MyClass
{
public:
	MyClass();
	~MyClass();
	MyClass(const MyClass &m);
private:
	int a;
};

MyClass::MyClass()
{
	cout << "构造函数" << endl;
}

MyClass::~MyClass()
{
	cout << "析构函数" << endl;
}
MyClass::MyClass(const MyClass &m)
{
	cout << "赋值构造函数" << endl;
}

MyClass getOne()
{
	MyClass oneExamp;
	return oneExamp;
}

void testConstructFum()
{
/* 情况一
	MyClass m;
	m = getOne();
*/
//情况二
	MyClass m = getOne();

}

int main01(int args,char*argus[])
{
	testConstructFum();
	system("pause");
	return 0;
}
/* 情况一
	运行流程：
	进入tesetConstructFun ,先构造 m 调用m的赋值构造函数，
	然后进入getone(),构造 oneExamp 调用 oneExamp 的构造函数 因为是将 return 出来的对象 初始化 m ,
	所以编译器将 调用 oneExamp 的 赋值构造函数 创建一个匿名对象保存在临时空间里，然后调用 oneExamp 的析构函数将
	oneExamp析构 ，然后利用此匿名对象初始化 m 然后再调用匿名对象的析构函数，将匿名对象析构掉，
	当执行到函数 getOne() 的最后一行后 m 的生命周期结束 ，调用 m 的析构函数，将m析构掉 

	情况二 



*/

