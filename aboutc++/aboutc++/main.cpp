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
	cout << "���캯��" << endl;
}

MyClass::~MyClass()
{
	cout << "��������" << endl;
}
MyClass::MyClass(const MyClass &m)
{
	cout << "��ֵ���캯��" << endl;
}

MyClass getOne()
{
	MyClass oneExamp;
	return oneExamp;
}

void testConstructFum()
{
/* ���һ
	MyClass m;
	m = getOne();
*/
//�����
	MyClass m = getOne();

}

int main01(int args,char*argus[])
{
	testConstructFum();
	system("pause");
	return 0;
}
/* ���һ
	�������̣�
	����tesetConstructFun ,�ȹ��� m ����m�ĸ�ֵ���캯����
	Ȼ�����getone(),���� oneExamp ���� oneExamp �Ĺ��캯�� ��Ϊ�ǽ� return �����Ķ��� ��ʼ�� m ,
	���Ա������� ���� oneExamp �� ��ֵ���캯�� ����һ���������󱣴�����ʱ�ռ��Ȼ����� oneExamp ������������
	oneExamp���� ��Ȼ�����ô����������ʼ�� m Ȼ���ٵ����������������������������������������
	��ִ�е����� getOne() �����һ�к� m ���������ڽ��� ������ m ��������������m������ 

	����� 



*/

