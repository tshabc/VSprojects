#pragma once
#include "socketprotocal.h"
class factory01 :public socketprotocal
{
public:
	factory01();
	~factory01();
	int cltSocketInit();
	int cltSocketSend( unsigned char *buf /*in*/, int buflen /*in*/) ;

	//客户端收报文
	int cltSocketRev( unsigned char *buf /*in*/, int *buflen /*in out*/) ;

	//客户端释放资源
	int cltSocketDestory() ;
public:
	char* tempbuff;
	int buflen;

};

