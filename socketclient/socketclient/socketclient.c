#pragma once
#pragma execution_character_set("utf-8")
#define  _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct _SOCKET
{
	char serverid[16];
	int serverport;
	int bufflenght;
	unsigned char *buf;

}SOCKET;

_declspec(dllexport)
int cltSocketInit(void **handle)
{
	SOCKET *SH = NULL;
	int ret = 0;
	if (handle == NULL)
	{
		printf("FileName %s,Func %s Line %d error ",__FILE__,__FUNCTION__,__LINE__);
		return ret;
	}
	SH = (SOCKET *)malloc(sizeof(SOCKET));
	if (SH == NULL)
	{
		printf("mallock failed ");
		ret = -1;
		return ret;
	}
	strcpy(SH->serverid,"192.168.1.100");
	SH->serverport = 88;

	*handle = SH;
	return 0;
}
_declspec(dllexport)
int cltSocketSend(void*handle, unsigned char *buf, int length)
{
	int ret = 0;
	if (handle == NULL ||buf == NULL||length == NULL)
	{
		ret = -1;
		printf("cltSocketSend Error");
		return ret;
	}
	SOCKET *sh = (SOCKET*)handle;
	sh->buf = (char*)malloc(length*sizeof(char));
	if (sh->buf == NULL)
	{
		ret = -1;
		printf("int cltSocketSend malloc failed");
		return ret;
	}
	
	//strcpy(sh->buf, buf);
	memcpy(sh->buf, buf, length);
	sh->bufflenght = length;
	return 0;
}
_declspec(dllexport)
int cltSocketRev(void *handle, unsigned char*buf, int *length)
{
	int ret = 0;
	if (handle == NULL || buf == NULL || length == NULL)
	{
		ret = -1;
		printf("cltSocketSend Error");
		return ret;
	}
	SOCKET *sh = (SOCKET*)handle;
	//strcpy(buf, sh->buf);
	memcpy(buf, sh->buf, sh->bufflenght);
	*length =sh->bufflenght;

	return 0;
}
_declspec(dllexport)
int cltSocketDestory(void *handle)
{
	if (handle != NULL)
	{
		if (((SOCKET*)handle)->buf != NULL)
		{
			free(((SOCKET*)handle)->buf);
			((SOCKET*)handle)->buf = NULL;
			((SOCKET*)handle)->bufflenght = 0;
		}
		free((SOCKET*)handle);		
	}
	return 0;
}


