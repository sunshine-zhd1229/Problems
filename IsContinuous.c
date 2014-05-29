/*
 * 从扑克牌中抽取n张，判断是否连续，大小王可作为任意一张牌
 */
#include  <stdio.h>
#define     true    1
#define     false   0

int IsContinuous(int *numbers, int length)
{
    if (numbers == NULL || length < 1)
      return false;
    else if (length == 1)
      return true;
    else if (length > 13)
      return false;

    int min = 14;
    int temp[14] = {0};

    for (int i = 0; i < length; i++) {
        temp[numbers[i]]++;
        if (numbers[i] < min && numbers[i] != 0)
          min = numbers[i];
    }

    for (int i = min; i < 14 && i < min + length; i++) {
        if (temp[i] == 0 && --temp[0] < 0)
          return false;
        else if (temp[i] > 1)
          return false;
    }

    return true;
}
