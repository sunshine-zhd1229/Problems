#include  <stdio.h>
#include  <stdlib.h>
#include  "StackArray.h"


//创建栈
Stack CreatStack(int MaxElements)
{
	Stack S;

	S = (Stack)malloc(sizeof(struct StackRecord));
	if(S == NULL)
	{
		printf("Out of Space for Stack Head!\n");
		return NULL;
	}

	S->Array = malloc(sizeof(ElementType) * MaxElements);
	if(S->Array == NULL)
	{
		printf("Out of Space for Stack Array!\n");
		free(S);
		return NULL;
	}

	S->Capacity = MaxElements;
	S->TopOfStack = EmptyTOS;
	return S;
}

//释放栈
void DisposeStack(Stack S)
{
	if(IsEmpty(S) > 0)
	{
		free(S->Array);
		free(S);
	}
}

//判断栈空, 空返回1, 非空返回0, 错误返回-1
int IsEmpty(Stack S)
{
	if(S == NULL)
	{
		printf("No Stack!\n");
		return -1;
	}
	if(S->Array == NULL)
	{
		printf("Stack Array has not assigned!\n");
		return -1;
	}
	return (S->TopOfStack == EmptyTOS);
}

//清空栈
void MakeEmpty(Stack S)
{
	if(IsEmpty(S) == 0)		//非空
	  S->TopOfStack = EmptyTOS;
}

//入栈
int Push(ElementType X, Stack S)
{

	if(IsFull(S) > 0)
	{
		printf("Stack Full!\n");
		return 0;
	}
	else
	{
		S->Array[++(S->TopOfStack)] = X;
		return 1;
	}
}

//返回栈顶元素
int Top(Stack S, ElementType *result)
{
	if(IsEmpty(S) == 0)	{	//非空
		*result =  S->Array[S->TopOfStack];
		return 0;
	}
	else
	  return -1;
}

//出栈
void Pop(Stack S)
{
	if(IsEmpty(S) == 0)		//非空
	  S->TopOfStack--;
}

int TopAndPop(Stack S, ElementType *x)
{
	if(IsEmpty(S) == 0)
	{
		*x = S->Array[S->TopOfStack--];
		return 1;
	}
	else
	  return 0;
}

//判断栈满, 栈满返回1, 不满返回0,出错返回-1
int IsFull(Stack S)
{
	if(IsEmpty(S) == 0)
	  return(S->TopOfStack == S->Capacity - 1);
	else
	  return -1;
}


