#include <stdlib.h>
//���ͷ�ļ���Ӧ�ĺ������Լ����Դ����� 10.cpp ��

typedef void  SeqList;
typedef struct _teg_seqlist 
{
	int capacity; //���Ա��е�ǰӵ�е�Ԫ�ظ���
	int length;   //���Ա��ܹ����Դ����Ԫ��������
	unsigned int * node;
}_teg_seqlist;

int seqListCreate(SeqList ** list,int capciti);

int seqListInsert(SeqList * list, void*newNode,int pos);

int seqListDelete(SeqList * list, int pos);

