#pragma once
#pragma execution_character_set("utf-8")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socketclientdll.h"


// ------------------第一套api接口---Begin--------------------------------//
// 客户端初始化 获取handle上下
// int cltSocketInit(void **handle /*out*/);
// 
// 客户端发报文
// int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/);
// 
// 客户端收报文
// int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/);
// 
// 客户端释放资源
// int cltSocketDestory(void *handle/*in*/);
// ------------------第一套api接口---End-----------------------------------//



int main()
{
	int  ret = 0;
	void *handle = NULL;
	unsigned char buff [20] = "asdfasdf";
	int bufflen = 0;
		bufflen = strlen(buff)+1;
	unsigned char buffrec[1024] ;
	int bufrecve = 0;
	printf("source buff = %s\n", buff);
	ret = cltSocketInit(&handle);
	if (ret != 0)
	{
		printf(" Initerror \n");
		return ret;
	}
	ret = cltSocketSend(handle /*in*/, buff /*in*/, bufflen /*in*/);
	if (ret != 0)
	{
		printf("cltSocketSend error \n");
		return ret;
	}
	ret = cltSocketRev(handle /*in*/, buffrec /*in*/, &bufrecve /*in out*/);
	if (ret != 0)
	{
		printf("cltSocketRev error \n");
		return ret;
	}
	printf("receve buff = %s\n", buffrec);
	ret =  cltSocketDestory(handle/*in*/);
	if (ret != 0)
	{
		printf("cltSocketDestory error \n");
		return ret;
	}

	system("pause");
	return 0;
}

