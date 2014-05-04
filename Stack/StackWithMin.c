#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  "StackArray.h"

struct StackMin{
	Stack stack;
	ElementType *min;
	int min_index;
};

typedef struct StackMin * StackWithMin;

//创建一个带有最小值的栈
StackWithMin createStackWithMin(int size) 
{
	StackWithMin stack_with_min = (StackWithMin)malloc(sizeof(struct StackMin));
	if (stack_with_min == NULL) {
		perror("create stack head failed.");
		return NULL;
	}

	stack_with_min->stack = CreatStack(size);
	if (stack_with_min->stack == NULL) {
		perror("create stack failed.");
		free(stack_with_min);
		return NULL;
	}

	stack_with_min->min = (ElementType *)malloc(stack_with_min->stack->Capacity * sizeof(ElementType));
	if (stack_with_min->min == NULL) {
		perror("create auxiliary stack failed.\n");
		free(stack_with_min->stack);
		free(stack_with_min);
		return NULL;
	}
	stack_with_min->min_index = -1;
	return stack_with_min;
}

//释放栈
void Dispose(StackWithMin stack) 
{
	if (stack == NULL)
	  return;
	if (stack->stack != NULL)
	  free(stack->stack);
	if (stack->min != NULL)
	  free(stack->min);
	free(stack);
}

//清空栈
void MakeStackWithMinEmpty(StackWithMin stack)
{
	if (stack == NULL) {
		printf("NULL argument.\n");
	  	return;
	}
	stack->stack->TopOfStack = EmptyTOS;
	stack->min_index = EmptyTOS;
}

//入栈, 出错返回-1, 成功返回0
int StackWithMinPush(StackWithMin stack, ElementType value) 
{
	if (stack == NULL) {
	 	printf("null argument.\n");
		return -1;
	}
	if (Push(value, stack->stack) == 0)
	  return -1;
	if (stack->min_index == -1 || value < stack->min[stack->min_index])
	  stack->min[++(stack->min_index)] = value;
	else
	  stack->min[++(stack->min_index)] = stack->min[stack->min_index - 1];
	return 0;
}

//出栈，出错返回-1, 成功返回0
int StackWithMinPop(StackWithMin stack, ElementType* result)
{
	if (stack == NULL) {
	 	printf("null argument.\n");
		return -1;
	}
	
	if (TopAndPop(stack->stack, result) == 1) {
	  	stack->min_index--;
		return 0;
	}
	return -1;
}

//取得栈内最小值, 出错返回-1, 成功返回0
int MinInStack(StackWithMin stack, ElementType *result)
{
	if (stack == NULL || stack->min_index == -1)
	  return -1;
	*result = stack->min[stack->min_index];
	return 0;
}

int main(void) 
{
	StackWithMin stack = createStackWithMin(7);
	int i = 0;
	ElementType value, min;
	for (; i < 10; i++) {
		if (StackWithMinPush(stack, i + (rand() % 8)) == 0 && MinInStack(stack, &min) == 0)
			printf("min: %d ", min);
	}

	printf("\n");

	for (; i >=0; i--) {
		if (MinInStack(stack, &min) == 0 && StackWithMinPop(stack, &value) == 0)
		  printf("value: %d, min: %d\n", value, min);
	}
	return 0;
}
