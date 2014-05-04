#include  <stdio.h>

int isLastOrderOfBST(int *checkSequence, int length)
{
	//检查输入
	if (checkSequence == NULL || length <= 0)
	  return 0;
	
	//小于3个节点时，一定能组成二叉搜索树
	if (length < 3)
	  return 1;

	int root = checkSequence[length - 1];
	int index = 0;
	
	//确定左子树
	for (; index < length - 1; index++) {
		if (checkSequence[index] > root)
		  break;
	}

	int length_of_left = index;
	int length_of_right = length - length_of_left - 1;

	//判断右子树是否全部大于根节点
	for (index++; index < length - 1; index++) {
		if(checkSequence[index] < root)
		  return 0;
	}

	//递归检查左子树
	if (length_of_left > 0 && !isLastOrderOfBST(checkSequence, length_of_left))
	  return 0;
		
	//递归检查右子树
	if (length_of_right > 0 && !isLastOrderOfBST(checkSequence + length_of_left, length_of_right))
	  return 0;

	return 1;
}

int main(void)
{
	int array1[7] = {5, 7, 6, 9, 11, 10, 8};
	int array2[6] = {3, 1, 5, 7, 6, 4};
	int array3[4] = {7, 4, 6, 5};
	printf("array1: ");
	if (isLastOrderOfBST(array1, 7))
	  printf("right\n");
	else
	  printf("wrong\n");

	printf("array2: ");
	if (isLastOrderOfBST(array2, 6))
	  printf("right\n");
	else
	  printf("wrong\n");

	printf("array3: ");
	if (isLastOrderOfBST(array3, 4))
	  printf("right\n");
	else
	  printf("wrong\n");
	return 0;
}
