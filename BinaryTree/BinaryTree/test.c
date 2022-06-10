#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

BTNode* BuyNode(BTDataType x)
{
	BTNode* a= (BTNode*)malloc(sizeof(BTNode));
	a->left = a->right = NULL;
	a->data = x;
	return a;
}

BTNode* creat()
{
	BTNode* a1 = BuyNode(1);
	BTNode* a2 = BuyNode(2);
	BTNode* a3 = BuyNode(3);
	BTNode* a4 = BuyNode(4);
	BTNode* a5 = BuyNode(5);
	BTNode* a6 = BuyNode(6);

	a1->left = a2;
	a1->right = a4;
	a2->left = a3;
	a4->left = a5;
	a4->right = a6;



	return a1;
}

void test1()
{
	BTNode* root = creat();
	//BinaryTreePrevOrder(root);
	//BinaryTreeInOrder(root);
	//BinaryTreePostOrder(root);
	//int ret=BinaryTreeSize(root);
	//printf("%d\n", ret);

	//int ret = BinaryTreeLeafSize(root);
	//printf("%d\n", ret);
	//int ret = BinaryTreeLevelKSize(root,1);
	//printf("%d\n", ret);
	int ret = TreeDepth(root);
	printf("%d\n", ret);

	BinaryTreeLevelOrder(root);

	printf("%d\n",BinaryTreeComplete(root));
	
}
BTNode* BuyNode1()
{
	BTNode* Node = (BTNode*)malloc(sizeof(BTNode));
	Node->left = Node->right = NULL;
	return Node;
}
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#' || a[*pi] == '\0')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* cur = BuyNode1();
	cur->data = a[*pi];
	(*pi)++;
	cur->left = BinaryTreeCreate(a, pi);
	cur->right =BinaryTreeCreate(a, pi);
	
	return cur;
}

void test2()
{
	char arr[101];
	int i = 0;
	scanf("%s", arr);
	BTNode* root = BinaryTreeCreate(arr, &i);

	BinaryTreePrevOrder(root);
}

int main()
{
	//test1();
	test2();
	return 0;
}

