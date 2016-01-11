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

	cout << "Hello World" << endl;
	system("pause");
	return 0;
}
