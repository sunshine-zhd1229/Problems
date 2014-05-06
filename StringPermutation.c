/*
 * 输入一个字符串，打印出字符串中字符的所有排列
 */

#include  <stdio.h>
#include  <string.h>

//交换x和y
void swap(char *x, char *y)
{
	if (x == y)
	  return;
	char temp = *x;
	*x = *y;
	*y = temp;
}

//递归全排列
void DoPermutation(char *str, char *begin)
{
	if (*begin == '\0')
	  printf("%s\n", str);
	else
	  for (char *ch = begin; *ch != '\0'; ch++) {
		 swap(ch, begin);
		 DoPermutation(str, begin + 1);
		 swap(ch, begin);
	  }
}

void Permutation(char *str)
{
	if (str == NULL)
	  return;
	DoPermutation(str, str);
}

//测试
int main(void)
{
	char buffer[100];
	memset(buffer, 0, 100);
	while(scanf("%s", buffer) != EOF)
	{
		Permutation(buffer);
		memset(buffer, 0, 100);
	}
	return 0;
}
