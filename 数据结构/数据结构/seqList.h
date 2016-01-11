#ifndef _SEQLIST_H_
#define _SEQLIST_H_
typedef void seqList;
typedef void seqListNode;
typedef struct handle
{
	int capacity;
	int length;
	unsigned int *node;
}handle;
seqList* seqList_create(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}
	handle* myhandle = (handle*)malloc(sizeof(handle));
	if (myhandle == NULL)
	{
		return NULL;
	}
	memset(myhandle, 0, sizeof(handle));
	myhandle->node = (unsigned int *)malloc(sizeof(unsigned int )*capacity);
	if (myhandle->node == NULL)
	{
		return NULL;
	}	
	memset(myhandle->node, 0, sizeof(unsigned int )*capacity);

	myhandle->capacity = capacity;
	myhandle->length = 0;
	return (seqList*)myhandle;
}
void seqList_destroy(seqList *head)
{
	if (head == NULL)
	{
		printf("param is Null ");
		return;
	}
	handle * myhandle = (handle*)head;
	if (myhandle->node != NULL)
	{
		free(myhandle->node);
		myhandle->node = NULL;
	}
	free(myhandle);


}
//Êý¾ÝÇåÁã
void seqList_clear(seqList *head)
{
	handle *myhandle = (handle*)head; 
	myhandle->capacity = 0;
	myhandle->length = 0;


}
int seqList_length(seqList*head)
{
	handle *myhandle = (handle*)head;
	return myhandle->length;
}
int seqList_capacity(seqList*head)
{
	handle *myhandle = (handle*)head;
	return myhandle->capacity;
}
int seqList_insert(seqList*head, seqListNode*node, int pos)
{
	int ret = 0;
	if (head == NULL||node == NULL)
	{
		printf("param error");
		return -1;
	}
	handle* myhandle = (handle*)head;
	if (myhandle->length > myhandle->capacity)
	{
		printf("can't insert agin ");
		return -1;
	}
	if (pos > myhandle->length || pos <0)
	{
		return -1;
	}
	if (myhandle->length == 0)
	{
		myhandle->node[myhandle->length] = (unsigned int)node;
		myhandle->length++;
		return 0;
	}
	int i = myhandle->length ;
	while (i != pos)
	{
		myhandle->node[i] = myhandle->node[i - 1];
		i--;
	}
	myhandle->node[pos] = (unsigned int)node;
	myhandle->length++;

	return 0;
}

seqListNode* seqList_getNode(seqList*head,int pos)
{
	handle * myhanle = (handle*)head;


	return (seqListNode*)(myhanle->node[pos]);
}
seqListNode* seqList_deleteNode(seqList*head, int pos)
{
	return NULL;
}

#endif