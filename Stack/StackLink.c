#include  <stdio.h>
#include  <stdlib.h>
#include  "StackLink.h"
typedef int ElementType;

struct Node
{
	ElementType Element;
	PtrToNode	Next;
};

//判断栈是否为空
int IsEmpty(Stack S)
{
	return (S->Next == NULL);
}

//创建空栈
Stack CreatStack(void)
{
	Stack S;

	S = (Stack)malloc(sizeof(struct Node));
	if(S == NULL)
	{
		perror("Out of Space! ");
		return NULL;
	}

	S->Next = NULL;
	S->Element = 0;
	return S;
}

//清空栈
void MakeEmpty(Stack S)
{
	if(S == NULL)
	{
		perror("Must use CreatStack first! ");
		return;
	}

	while(!IsEmpty(S))
	  Pop(S);
}

//返回栈顶第一个元素
ElementType Top(Stack S)
{
	if(S->Next == NULL)
	{
		printf("Empty Stack!\n");
		return 0;
	}
	else
	  return S->Next->Element;
}

//入栈
void Push(ElementType X, Stack S)
{
	PtrToNode TmpCell;

	TmpCell = (PtrToNode)malloc(sizeof(struct Node));
	if(TmpCell == NULL)
	{
		perror("Out of Space! ");
		return;
	}
	TmpCell->Element = X;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
}

//出栈
void Pop(Stack S)
{
	PtrToNode FirstCell;

	if(S->Next == NULL)
	  printf("Empty Stack!\n");
	else
	{
		FirstCell = S->Next;
		S->Next = FirstCell->Next;
		free(FirstCell);
	}
}
