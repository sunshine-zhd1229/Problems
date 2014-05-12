/*
 * 在有序数组中找到和为sum的两个数
 */
#include  <stdio.h>

int FindNumbersWithSum(int *numbers, int length, int sum, int *num1, int *num2)
{
    if (!numbers || length < 2 || !num1 || !num2)
      return -1;

    int *ptr1 = numbers, *ptr2 = numbers + length - 1;

    while (ptr1 != ptr2) {
        long long temp = *ptr1 + *ptr2;
        if (temp > sum)
          ptr2--;
        else if (temp < sum)
          ptr1++;
        else {
            *num1 = *ptr1;
            *num2 = *ptr2;
            return 0;
        }
    }
    return -1;
}

