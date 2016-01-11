#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
class quanjv
{
public:
	quanjv()
	{
		cout << "全局对象的构造函数,会在main 函数之前执行" << endl;
	}
protected:
private:
};
quanjv q;
int main(int args,char*argus[])
{

	map<string,int> mymap;


	mymap.insert(pair<string, int>("asdf", 0));
	mymap.insert(map<string, int>::value_type("second", 2));
	mymap.insert(map<string, int>::value_type("thired", 1));

	map<string, int> ::iterator mit;
	for (mit = mymap.begin(); mit!= mymap.end();mit++)
	{
		cout<<mit->second<<" "<<(mit->first).c_str() <<endl;
	}
	string s = "aasdf";
	cout << s.c_str() << endl;


	map<string, int> mymap01(mymap);
	mit = mymap01.begin();
	for (mit = mymap01.begin(); mit != mymap01.end(); mit++)
	{
		cout << mit->second << " " << (mit->first).c_str() << endl;
	}

	system("pause");
	return 0;
}
