/*
 * 输入一个正整数数组，输出由这些正整数组成的最小整数
 * 解法：设两个数m和n，比较所构成的数mn和nm的大小，以确定m和n的排列顺序
 */

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

#define     MAXLENGTH   10

//用于存储mn和nm
char combine1[MAXLENGTH * 2 + 1];
char combine2[MAXLENGTH * 2 + 1];

//用于qsort的比较函数
int compare(const void *a, const void *b)
{
    strcpy(combine1, a);
    strcat(combine1, b);

    strcpy(combine2, b);
    strcat(combine2, a);

    //比较mn和nm
    return strcmp(combine1, combine2);
}

void PrintMinNumber(int *numbers, int length)
{
    if (numbers == NULL || length <= 0)
      return;

    char SortArray[length][MAXLENGTH + 1];  //用于将整数转换成字符串
    
    //将数字转换成字符串
    for (int i = 0; i < length; i++) {
      sprintf(SortArray[i], "%d", numbers[i]);
      printf("%s\n", SortArray[i]);
    }

    qsort(SortArray, length, MAXLENGTH + 1, compare);

    //打印
    for (int i = 0; i < length; i++)
      printf("%s", SortArray[i]);
    printf("\n");
}

