#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "socketprotocal.h"
#include "factory01.h"

using namespace std;
//一个收发报文逻辑模拟
int main(int args,char*argus[])
{
	unsigned char buff[1024] = { 0 };
	int sendlen = 20;
	unsigned char out[1024] = { 0 };
	int outlen = 0;
	strcpy((char*)buff, "sendsaldfkjasdfasdf");

	socketprotocal *sp = NULL;
	sp = new factory01;
	sp->cltSocketInit();
	sp->cltSocketSend(buff, sendlen);
	sp->cltSocketRev(out, &outlen);
	sp->cltSocketDestory();


	cout << out << endl;
	system("pause");
	return 0;
}
