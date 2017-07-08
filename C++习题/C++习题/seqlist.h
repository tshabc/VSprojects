#include <stdlib.h>
//与此头文件对应的函数体以及测试代码在 10.cpp 内

typedef void  SeqList;
typedef struct _teg_seqlist 
{
	int capacity; //线性表中当前拥有的元素个数
	int length;   //线性表总共可以储存的元素总上限
	unsigned int * node;
}_teg_seqlist;

int seqListCreate(SeqList ** list,int capciti);

int seqListInsert(SeqList * list, void*newNode,int pos);

int seqListDelete(SeqList * list, int pos);

