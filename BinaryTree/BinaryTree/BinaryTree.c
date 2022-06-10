#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"
#include "queue.h"

// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
		
	printf("%c ", root->data);
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

	BTNode* ret1=BinaryTreeFind(root->left,x);
	if (ret1)
		return ret1;
	BTNode* ret2 = BinaryTreeFind(root->right, x);
	if (ret2)
		return ret2;

	return NULL;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1)+ BinaryTreeLevelKSize(root->right, k - 1);

}

int TreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;

	int ret1 = TreeDepth(root->left);
	int ret2 = TreeDepth(root->right);

	if (ret1 > ret2)
		return ret1+1;
	else
		return ret2+1;

}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		QueuePop(&q);
		if (cur == NULL)
			printf("# ");
		else
		{
			printf("%d ", cur->data);
			QueuePush(&q, cur->left);
			QueuePush(&q, cur->right);
		}
	}
	QueueDestroy(&q);
	printf("\n");
}

bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		QueuePop(&q);
		if (cur == NULL)
			break;
		else
		{
			QueuePush(&q, cur->left);
			QueuePush(&q, cur->right);
		}
	}
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		QueuePop(&q);
		if (cur != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}

	QueueDestroy(&q);
	return true;
}

void BinaryTreeDestory(BTNode** root)
{

}