#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
		
	printf("%d ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);

}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%d ", root->data);
	
	BinaryTreeInOrder(root->right);
	
	
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%d ", root->data);
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return 1+ BinaryTreeSize(root->left)+ BinaryTreeSize(root->right);

}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;

	BTNode* ret1=BinartTreeFind(root->left,x);
	if (ret1)
		return ret1;
	BTNode* ret2 = BinartTreeFind(root->right, x);
	if (ret2)
		return ret2;

}