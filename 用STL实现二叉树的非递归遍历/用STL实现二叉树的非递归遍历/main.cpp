#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

typedef struct TreeNode
{
	int data;
	struct TreeNode* leftChild;
	struct TreeNode* rightChild;

}TreeNode,*pTreeNode;
//�㷨���� 
/* ���㷨���� ������������㷨
	1.���ϵĳ��Բ��ҽ���Ƿ������ӽ��
	2.�����ǰ���û�����ӽ�㣬��ô��ǰ�����ջ���������ô �ظ����� 1
	3.���Բ��ҵ�ǰ�������ӽ�㣬��������ӽ�㣬��ô�ظ����� 1�����û����ô ��ջ������Ԫ�ص���
*/


void readTree(stack<TreeNode*> *treeStack, TreeNode* node)
{
	if (treeStack == NULL)
	{
		cout << " stack can not be Null error" << endl;
		return ;
	}

	if (node->leftChild != NULL)
	{
		treeStack->push(node);
		readTree(treeStack,node->leftChild);
	}
	else
	{
		cout << node->data << endl;
	}
	if (node->rightChild != NULL)
	{
		readTree(treeStack, node->rightChild);
	}
	else
	{
		while (!treeStack->empty())
		{
			TreeNode* temp = treeStack->top();
			cout << temp->data << endl;
			treeStack->pop();
		}
	}
}
// �����Ľṹ����ԴͼƬ
int main(int args,char*argus[])
{
	TreeNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(t1));
	memset(&t2, 0, sizeof(t2));
	memset(&t3, 0, sizeof(t3));
	memset(&t4, 0, sizeof(t4));
	memset(&t5, 0, sizeof(t5));
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	// ��t1ΪΪ�����
	t1.leftChild = &t2;
	t1.rightChild = &t3;
	// t2�ӽ��
	t2.leftChild = &t4;
	t2.rightChild = NULL;

	//t3 �ӽ��
	t3.rightChild = &t5;


	stack<TreeNode*> treeStack;

	readTree(&treeStack, &t1);

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
