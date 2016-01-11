#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _liststudy
{
	int data;
	struct _liststudy *next;

}liststudy;

int initList(liststudy ** mylist)
{

	int ret = 0;
	if (mylist == NULL)
	{
		ret = -1;
		printf("the param can not be NULL error number : %d", ret);
		return ret;
	}
	int data = 0;
	printf("plase in put data ,-1 to stop\n");
	scanf("%d", &data);
	*mylist = (liststudy *)malloc(sizeof(liststudy));
	(*mylist)->data = data;
	(*mylist)->next = NULL;
	liststudy *phead;
	liststudy *pcur;
	phead = *mylist;
	pcur = phead;
	//liststudy *pm
	while (data != -1)
	{
		scanf("%d", &data);
		liststudy * pm = (liststudy *)malloc(sizeof(liststudy));
		pm->next = NULL;
		pm->data = data;
		pcur->next = pm;
		pcur = pm;
		
	}

	return ret;
}
int insertNode(liststudy*mylist, int indexData, int newNodevalue)
{
	int ret = 0;
	if (mylist == NULL)
	{
		ret = -1;
		printf("the param can not be NULL error number : %d", ret);
		return ret;
	}
	liststudy *ppre;
	liststudy *pcur;
	liststudy *pnext;
	pcur = ppre = pnext = mylist;
	while (pnext != NULL)
	{
		if (pnext->data == indexData)
		{
			liststudy *ptemp = (liststudy*)malloc(sizeof(liststudy));
			ptemp->data = newNodevalue;
			ptemp->next = pnext;
			ppre->next = ptemp;
			break;
		}
		else
		{
			ppre = pnext;
			pnext = pnext->next;			
		}
	}

	return ret;
}
int outputList(liststudy*mylist)
{
	int ret = 0;
	if (mylist == NULL)
	{
		ret = -1;
		printf("the param can not be NULL error number : %d", ret);
		return ret;
	}
	liststudy * ptem = mylist;
	while (ptem->next != NULL)
	{
		printf("%d \n",ptem->data);
		ptem = ptem->next;
	}



	return ret;
}

int main()
{
	printf("Á´±í\n");
	int ret = 0;
	liststudy * mylist = NULL;
	ret = initList(&mylist);
	ret = outputList(mylist);
	ret = insertNode(mylist, 3, 10);
	ret = outputList(mylist);


	const int asdf = 1;
	const int * p = NULL;
	p = &asdf;

	system("pause");
	return 0;
}


