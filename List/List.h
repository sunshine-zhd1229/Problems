typedef int ElementType;
struct Node{
	ElementType 	Element;
	int 			reserve;
	struct Node*	Next;
};

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Postion;

int IsEmpty(List L);
int IsLast(Postion P, List L);
Postion Find(ElementType X, List L);
void Delete(ElementType X, List L);
Postion FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Postion P);
void DeleteList(List L);

