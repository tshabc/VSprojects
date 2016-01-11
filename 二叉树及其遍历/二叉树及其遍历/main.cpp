#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;


typedef struct treeNode
{
	struct treeNode *leftChild, *rightChild;
	int data;
}TreeNode,*ptree;

//树的递归遍历
void readTree(TreeNode*node)
{
	if (node!=NULL)
	{
		readTree(node->leftChild);
		cout << "data = " << node->data << endl;
		readTree(node->rightChild);
	}
	
}
//二叉树的叶子结点数
void treeLeafNum(TreeNode * tree, int *num)
{
	if (tree != NULL)
	{
		//当一个结点 左右都没有子结点时，它是一个叶子
		if (tree->leftChild == NULL && tree->rightChild == NULL) 
		{
			(*num)++;
		}
		treeLeafNum(tree->leftChild, num);
		treeLeafNum(tree->rightChild, num);
	}
}
//二叉树的深度
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
// 二叉树的复制
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

	// 以t1为为根结点
	t1.leftChild = &t2;
	t1.rightChild = &t3;
	// t2子结点
	t2.leftChild = &t4;
	t2.rightChild = NULL;

	//t3 子结点
	t3.rightChild = &t5;
	readTree(&t1);
	// 二叉树的叶子结点数
	int leafNum = 0;
	treeLeafNum(&t1, &leafNum);
	cout << "叶子结点数 = " << leafNum << endl;
	//二叉树的深度
	int depth = 0;
	depth = treeDepth(&t1);
	cout << "二叉树的深度 = " << depth << endl;
	//二叉树的复制
	TreeNode * copytree = NULL;
	copytree = treeCopy(&t1);
	cout << "复制结果" << endl;
	readTree(&t1);


	cout << "Hello World" << endl;
	system("pause");
	return 0;
}
