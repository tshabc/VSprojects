#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
struct test
{
	int a;
};
void testDress()
{
	test tes;
	tes.a = 1;
	cout << "&tes\t" << &tes << endl;
	cout << "&(tes.a\t)" << &(tes.a) << endl;
}
int main12(int args,char*argus[])
{
	testDress();

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
