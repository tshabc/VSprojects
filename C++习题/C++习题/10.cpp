#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include "seqlist.h"
using namespace std;

int seqListCreate(SeqList ** list, int capciti)
{
	int ret = 0;
	
	if (NULL == list )
	{
		cout<<"list ����Ϊ��" << __FILE__ << __LINE__ << endl;
	}
	_teg_seqlist* myseqlist = NULL;
	if (capciti<1)
	{
		cout << "can not create" << __FILE__ << __LINE__ << __FUNCTION__ << endl;
	}
	myseqlist = (_teg_seqlist*)malloc(sizeof(_teg_seqlist) + sizeof(unsigned int )+capciti);
	if (NULL == myseqlist)
	{
		cout << "�����ڴ�ʧ��" << endl;
	}
	memset(myseqlist, 0, sizeof(_teg_seqlist)+sizeof(unsigned int )+capciti);
	myseqlist->node = (unsigned int *)(myseqlist + 1);
	myseqlist->length = 0;
	myseqlist->capacity = capciti;
	*list = myseqlist;
	return ret;

}

int seqListInsert(SeqList * list, void*newNode,int pos)
{
	int ret = 0;
	if (NULL == list)
	{
		ret =  -1;
	}
	_teg_seqlist* seq = (_teg_seqlist*)list;
	unsigned int * p = seq->node;
	if (pos<0 ||pos>seq->length)
	{
		return -2;
	}
	if (seq->capacity>= seq->length)
	{
		cout << "�������Ʋ����ٲ���" << endl;
		return -3; 
	}
	//�Ѻ�������ݺ���
	int i = 0;
	for ( i = seq->capacity; i > pos;i--)
	{
		seq->node[i] = seq->node[i - 1];
	}
	seq->node[i] = (unsigned int)newNode;
	seq->length++;
	return 0;
}

int seqListDelete(SeqList * list, int pos)
{

	return 0; 
}

int main10(int args,char*argus[])
{
	string str = "asdfs";
	map<int, string> mym;
	mym.insert(pair<int, string>(1, "asdf"));
	map<int, string>::iterator it = mym.begin();
	for (it; it != mym.end();it++)
	{
		cout << it->first << endl;
		cout << (it->second).c_str() << endl;
	}

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
