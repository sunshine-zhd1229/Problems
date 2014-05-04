#define EmptyTOS -1
#define     MinStackSize 100

typedef int ElementType;

struct StackRecord{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

typedef struct StackRecord *Stack;
int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreatStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
int Push(ElementType X, Stack S);
int Top(Stack S, ElementType *X);
void Pop(Stack S);
int TopAndPop(Stack S, ElementType *X);
