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
//算法讲解 
/* 本算法采用 树的中序遍历算法
	1.不断的尝试查找结点是否有左子结点
	2.如果当前结点没有左子结点，那么当前结点入栈，如果有那么 重复步骤 1
	3.尝试查找当前结点的右子结点，如果有右子结点，那么重复步骤 1，如果没有那么 将栈内所有元素弹出
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
// 本树的结构见资源图片
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

	// 以t1为为根结点
	t1.leftChild = &t2;
	t1.rightChild = &t3;
	// t2子结点
	t2.leftChild = &t4;
	t2.rightChild = NULL;

	//t3 子结点
	t3.rightChild = &t5;


	stack<TreeNode*> treeStack;

	readTree(&treeStack, &t1);

	cout<<"Hello World"<<endl;
	system("pause");
	return 0;
}
