/*
 * 输入两个整数数列，第一个序列表示压栈顺序，判断第二个序列是否为合理的出栈顺序
 * 如：入栈顺序为 1, 2, 3, 4， 5; 则出栈顺序5, 4, 3, 2, 1是一个合理的出栈序列
 *
 * 入口：压栈序列 出栈序列 序列长度
 * 返回值：是合理的出栈序列返回1, 不是返回0, 出错返回值小于0
 *
 * 可能的出错原因，申请栈内存不成功，输入参数错误
 */

#include  <stdio.h>
#include  "StackArray.h"
#define   EARGUMENT -1
#define   EMEMORY -2

int isPopOrder(int* PushOrder, int *PopOrder, int size)
{
	if (PushOrder == NULL || PopOrder == NULL || size <= 0) {
		printf("arguments error\n");
		return EARGUMENT;
	}
	
	Stack stack = CreatStack(size);
	if (stack == NULL) {
		printf("create stack error\n");
		return EMEMORY;
	}
	
	int push_index = -1;	//push_index指向PushOrder当中，与当前检查的值相等的元素的下标
	int pop_index = 0;
	int value;				//用于存储栈顶元素

	for (; pop_index < size; pop_index++) {
		//检查当前元素是否与栈顶元素相等
		if (Top(stack, &value) == 0 && value == PopOrder[pop_index]) {
			Pop(stack);
			continue;
		}
		
		//检查入栈序列中是否与当前值相等的值，并将该值之前的数字压入栈中
		push_index++;
		while(push_index < size) {
			if (PushOrder[push_index] != PopOrder[pop_index])
			  Push(PushOrder[push_index++], stack);
			else
			  break;
		}
		
		//若所有值都与检查值不相等，说明该序列不是一个合理的出栈序列
		if(push_index >= size)
		  return 0;
	}

	//出栈序列中所有值都通过了检查，说明该序列是一个合理的出栈序列
	return 1;
}

//测试
int main(void)
{
	int PushOrder[5] = {1, 2, 3, 4, 5};
	int PopOrder[5] = {4, 3, 2, 1, 5};

	if (isPopOrder(PushOrder, PopOrder, 5))
	  printf("is pop order\n");
	else
	  printf("is not pop order\n");
	return 0;
}
