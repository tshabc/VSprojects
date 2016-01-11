#include "factory01.h"
#include "stdlib.h"
#include <string.h>
factory01::factory01()
{
	tempbuff = NULL;
	buflen = 0;
}


factory01::~factory01()
{
	if (tempbuff != NULL)
	{
		free(tempbuff);
		tempbuff = NULL;
		buflen = 0;
	}
}
int factory01::cltSocketInit()
{
	int ret = 0;
	tempbuff = NULL;
	buflen = 0;
	return ret;
}

//客户端发报文
int factory01::cltSocketSend( unsigned char *buf /*in*/, int buflen /*in*/)
{
	int ret = 0;

	tempbuff = (char*)malloc(sizeof(char)*buflen);
	memcpy(tempbuff, buf, buflen);
	this->buflen = buflen;
	return ret;
}

//客户端收报文
int factory01::cltSocketRev( unsigned char *buf /*in*/, int *buflen /*in out*/)
{
	int ret = 0;
	memcpy(buf, this->tempbuff, this->buflen);
	*buflen = this->buflen;

	return ret;
}

//客户端释放资源
int factory01::cltSocketDestory()
{
	int ret = 0;
	if (tempbuff != NULL)
	{
		free(tempbuff);
		tempbuff = NULL;
		buflen = 0;
	}
	return ret;
}