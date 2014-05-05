/*
 * 输入一个二叉树，打印出所有和为某一值的路径
 *
 * 利用一个链表存储路径，在二叉树上进行递归搜索
 */
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  "List/List.h"
#include  "Tree/BinarySearchTree.h"

List path_head;		//用于存储路径的链表
Postion tail, pre_tail = NULL;

//打印从根节点的父节点的路径
void PrintPath() 
{
	Postion p = path_head->Next;
	while(p != NULL) {
		printf("%d ", p->Element);
		p = p->Next;
	}
}

//递归搜索路径
void DoFind(TreeNode *tree, int sum) {
	if (tree == NULL)
	  return;
	if (tree->left == NULL && tree->right == NULL) {
		//叶子节点
		if (*(int*)(tree->data) == sum) {
			PrintPath();
			printf("%d\n", *(int*)(tree->data));
		}
	} else {
		//将该节点插入路径列表末尾
		if (Insert(*(int*)(tree->data), tail) == -1) {
		  exit(1);
		}
		pre_tail = tail;
		tail = tail->Next;
		//查找左子树
		if (tree->left != NULL)
			DoFind(tree->left, sum - tail->Element);
		//查找右子树
		if (tree->right != NULL)
		  DoFind(tree->right, sum - tail->Element);
		//在路径中删除当前节点
		pre_tail->Next = NULL;
		free(tail);
		tail = pre_tail;
	}
}

//初始化链表，维护尾指针
void FindPath(TreeNode* tree, int sum) 
{
	path_head = (List)malloc(sizeof(struct List_Node));
	if (path_head == NULL)
	{
		perror("allocate path list error: ");
		return;
	}
	path_head->Next = NULL;
	tail = path_head;
	DoFind(tree, sum);
}

//以下函数用于测试
//定义的二叉树利用void*存储任何类型数据，需定义一个compare函数，用于向二叉搜索树中插入节点时比较大小
int compare(const void *a, const void *b)
{
	if (*(int*)a > *(int *)b)
	  return 1;
	else if(*(int*)a < *(int *)b)
	  return -1;
	else
	  return 0;
}

int main(void) 
{	
	int array[5] = {10, -5, 16, -14, 7};
	TreeNode* tree = CreateTree(array, 5, sizeof(int), compare);
	FindPath(tree, -9);
	return 0;
}
