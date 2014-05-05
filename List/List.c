#include  <stdio.h>
#include  <stdlib.h>
#include  "List.h"

//判断链表为空
int IsEmpty(List L)
{
	return (L->Next == NULL);
}

//判断P是否位于链表尾
int IsLast(Postion P, List L)
{
	return(P->Next == NULL);
}

//查找指定元素
Postion Find(ElementType X, List L)
{
	Postion P;
	P = L->Next;
	while((P->Next != NULL) && (P->Element != X))   //注意判断顺序
	  P = P->Next;
	return P;
}

//删除表中指定元素，删除首次出现的元素
void Delete(ElementType X, List L)
{
	Postion P, TmpCell;
	P = FindPrevious(X, L);

	if(!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

//查找指定元素的前驱
Postion FindPrevious(ElementType X, List L)
{
	Postion P;

	P = L;
	while((P->Next != NULL) && (P->Next->Element != X))
	  P = P->Next;
	return P;
}

//将新元素插入到指定节点之后
int Insert(ElementType X, Postion P)
{
	Postion TmpCell;
	if(P == NULL)
	  return 0;
	TmpCell = (Postion)malloc(sizeof(struct List_Node));
	if(TmpCell == NULL) {
	  perror("malloc in Insert error: ");
	  return -1;
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
	return 1;
}

//删除表
void DeleteList(List L)
{
	Postion P, Tmp;
	P = L->Next;
	while(P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}
