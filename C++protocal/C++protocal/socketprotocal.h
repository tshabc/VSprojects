#pragma once
class socketprotocal
{
public:
	socketprotocal();
	virtual ~socketprotocal();

	virtual int cltSocketInit() = 0;

	//�ͻ��˷�����
	virtual int cltSocketSend( unsigned char *buf /*in*/, int buflen /*in*/) = 0;

	//�ͻ����ձ���
	virtual int cltSocketRev( unsigned char *buf /*in*/, int *buflen /*in out*/) = 0;

	//�ͻ����ͷ���Դ
	virtual int cltSocketDestory() = 0;

};

