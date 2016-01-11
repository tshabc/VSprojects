#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
template <class T>
class complex
{
public:
	complex();
	complex(T a, T b);
	complex(const complex &c);
	~complex();
public:
	friend	complex operator+<T>(complex<T> &c, complex<T> &d);
		
public:
	int a;
	int b;
private:
};
template <class T>
complex<T>::complex()
{

}
template <class T>
complex<T>::complex(T a, T b)
{
	this->a = a;
	this->b = b;
}
template <class T>
complex<T>::complex(const complex &c)
{
	this->a = c.a;
	this->b = c.b;
}
template <class T>
complex<T>::~complex()
{
}
template <class T>
complex<T> operator+(complex<T> &c,complex<T> &d)
{

	complex<T> temp(d.a + c.a, d.b + c.b);
	/*this->a = this->a + c.a;
	this->b = this->b + c.b;
	return *this;*/
	return temp;
}
int main(int args,char*argus[])
{

	complex<int> a(1, 2);
	complex<int> b(3, 4);
	//a + b;
	complex<int> c;
	 c = b + a;
	 complex<int> d;
	 d = a + b + c;
	 cout << "c.a = " << c.a << endl;
	 cout << "c.b = " << c.b << endl;
	 
	 cout << "d.a = " << d.a << endl;
	 cout << "d.b = " << d.b << endl;
	system("pause");
	return 0;
}
