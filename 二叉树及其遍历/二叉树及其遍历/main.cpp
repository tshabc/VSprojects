#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;


typedef struct treeNode
{
	struct treeNode *leftChild, *rightChild;
	int data;
}TreeNode,*ptree;

//���ĵݹ����
void readTree(TreeNode*node)
{
	if (node!=NULL)
	{
		readTree(node->leftChild);
		cout << "data = " << node->data << endl;
		readTree(node->rightChild);
	}
	
}
//��������Ҷ�ӽ����
void treeLeafNum(TreeNode * tree, int *num)
{
	if (tree != NULL)
	{
		//��һ����� ���Ҷ�û���ӽ��ʱ������һ��Ҷ��
		if (tree->leftChild == NULL && tree->rightChild == NULL) 
		{
			(*num)++;
		}
		treeLeafNum(tree->leftChild, num);
		treeLeafNum(tree->rightChild, num);
	}
}
//�����������
int treeDepth(TreeNode* tree)
{
	int depth = 0;
	int leftDepth = 0;
	int rightDepth = 0;
	if (tree == NULL)
	{
		depth = 0;
		return depth;
	}
	leftDepth = treeDepth(tree->leftChild);
	rightDepth = treeDepth(tree->rightChild);
	
	depth = (leftDepth > rightDepth) ? leftDepth : rightDepth;
	return depth + 1 ;
}
// �������ĸ���
TreeNode * treeCopy(TreeNode * tree)
{
	TreeNode * leftNode = NULL;
	TreeNode * rightNode = NULL;

	if (tree->leftChild != NULL)
	{
		leftNode = treeCopy(tree->leftChild);
	}
	if (tree->rightChild != NULL)
	{
		rightNode = treeCopy(tree->rightChild);
	}
	TreeNode * node = (TreeNode*)malloc(sizeof(TreeNode));
	node->leftChild = leftNode;
	node->rightChild = rightNode;
	node->data = tree->data;
	return node;
}

//���õݹ�������ı���
// ������Ҷ�ӣ�ֱ��û�У������н����ŵ�ջ��
stack<TreeNode*> treeStack;
TreeNode* findLeftC(TreeNode* node) //�˺���һֱ�����ң����Ѿ����Ľ�����ջ��
{
	TreeNode* t = NULL;
	if (NULL == node)
	{
		return NULL;
	}
	t = node;
	while (NULL !=t)
	{
		if (t->leftChild !=NULL)
		{
			treeStack.push(t);
			t = t->leftChild;
		}
		else
		{
			break;
		}
		
	}
	return t;
}
//��������м����
void bianli(TreeNode* node)
{
	if (NULL == node)
	{
		return;
	}
	TreeNode* t = findLeftC(node);
	while (t)
	{
		printf("%d", t->data); //��ӡ����
		if (t->rightChild != NULL)
		{
			t = findLeftC(t->rightChild);
		}
		else if (!treeStack.empty())
		{
			t = treeStack.top();
			treeStack.pop();
		}
		else 
		{
			t = NULL;
		}
		

	}
	cout << endl;
}

int main(int args,char*argus[])
{
	TreeNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(t1));
	memset(&t2, 0, sizeof(t2));
	memset(&t3, 0, sizeof(t3));
	memset(&t4, 0, sizeof(t4));
	memset(&t5, 0, sizeof(t5));
	t1.data = 1	;
	t2.data = 2	;
	t3.data = 3	;
	t4.data = 4	;
	t5.data = 5	;

	// ��t1ΪΪ�����
	t1.leftChild = &t2;
	t1.rightChild = &t3;
	// t2�ӽ��
	t2.leftChild = &t4;
	t2.rightChild = NULL;

	//t3 �ӽ��
	t3.rightChild = &t5;
	readTree(&t1);
	// ��������Ҷ�ӽ����
	int leafNum = 0;
	treeLeafNum(&t1, &leafNum);
	cout << "Ҷ�ӽ���� = " << leafNum << endl;
	//�����������
	int depth = 0;
	depth = treeDepth(&t1);
	cout << "����������� = " << depth << endl;
	//�������ĸ���
	TreeNode * copytree = NULL;
	copytree = treeCopy(&t1);
	cout << "���ƽ��" << endl;
	readTree(copytree);

	cout << "�ǵݹ�����������" << endl;
	bianli(&t1);

	cout << "Hello World" << endl;
	system("pause");
	return 0;
}
