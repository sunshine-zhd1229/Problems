/*
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字
 * 算法1：出现次数超过数组长度的一半，则一定是数组的中位数，可转化为找第n/2大的数
 * 算法2：每次去掉一对不一样的数，则剩下的一定是出现次数超过一半的数
 */

#include  <stdio.h>
#include  <stdlib.h>
#include  <time.h>
#include  "MoreThanHalfNumber.h"

//标志输入参数是否出错，输入数组是否符合要求
int ErrorFlag = 0;

//利用快排的Partition找第n/2大的数
int MoreThanHalfNum1(int *numbers, int length)
{
    ErrorFlag = 0;
    if (numbers == NULL || length <= 0) {
        ErrorFlag = 1;
        return 0;
    }

    int start = 0, end = length, middle = length >> 1, index;
    while(1) {
        index = Partition(numbers, start, end);
        if (index > middle)
          end = index - 1;
        else if(index < middle)
          start = index + 1;
        else
          break;
    }
    
    if(CheckMoreThanHalf(numbers, length, numbers[middle]))
      return numbers[middle];
    else
      return 0;
}

int Partition(int *array, int start, int end) 
{
    if(start == end)
      return start;

    //数组中随机挑选一个数与最后一个数交换
    RandSwap(array, start, end);
    //i指向最后一个小于array[end]的数
    int i = start - 1, j = start;
    for(; j < end; j++) {
        if (array[j] < array[end]) {
            i++;
            if (i != j) {
                Swap(array + i, array + j);
            }
        }    
    }
    i++;
    Swap(array + i, array + j);
    return i;
}

//在start和end之间随机选取一个数与array[end]交换
void RandSwap(int *array, int start, int end)
{
    srand(time(NULL));
    int i = (rand() % (end - start)) + start;
    Swap(array + i, array + end);
}

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//检查找到的数出现的次数是否超过数组长度的一半
int CheckMoreThanHalf(int *array, int length, int num) 
{
    ErrorFlag = 0;
    int count = 0;
    int i;
    for (i = 0; i < length; i++)
      if (array[i] == num)
        count++;

    if (count * 2 > length)
      return 1;
    else {
        ErrorFlag = 1;
        return 0;
    }
}

//每次去掉一对不一样的数
int MoreThanHalfNum2(int *array, int length)
{
    ErrorFlag = 0;
    if (array == NULL || length <= 0)
    {
        ErrorFlag = 1;
        return 0;
    }

    int i, time = 1, result = array[0];

    for (i = 1; i < length; i++) {
        if (time == 0) {
          result = array[i];
          time = 1;
        }
        else {
            if (array[i] == result)
              time++;
            else
              time--;
        }
    }

    if (CheckMoreThanHalf(array, length, result))
      return result;
    else
      return 0;
}

