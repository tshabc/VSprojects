#pragma once
#include "socketprotocal.h"
class factory01 :public socketprotocal
{
public:
	factory01();
	~factory01();
	int cltSocketInit();
	int cltSocketSend( unsigned char *buf /*in*/, int buflen /*in*/) ;

	//�ͻ����ձ���
	int cltSocketRev( unsigned char *buf /*in*/, int *buflen /*in out*/) ;

	//�ͻ����ͷ���Դ
	int cltSocketDestory() ;
public:
	char* tempbuff;
	int buflen;

};

