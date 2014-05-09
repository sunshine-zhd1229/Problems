typedef int ElementType;
struct List_Node{
	ElementType 	Element;
	int 			reserve;
	struct List_Node*	Next;
};

typedef struct List_Node *PtrToNode;
typedef struct List_Node ListNode;
typedef PtrToNode List;
typedef PtrToNode Postion;

int IsEmpty(List L);
int IsLast(Postion P, List L);
Postion Find(ElementType X, List L);
void Delete(ElementType X, List L);
Postion FindPrevious(ElementType X, List L);
int Insert(ElementType X, Postion P);
void DeleteList(List L);

