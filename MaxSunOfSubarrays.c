/*
 * 输入一个数组，求所有子数组的和的最大值
 */

#include  <stdio.h>

int ErrorFlag = 0;

int MaxSumOfSubarrays(int *array, int length)
{
    ErrorFlag = 0;
    if (array == NULL || length <= 0) {
        ErrorFlag = 1;
        return -1;
    }

    int sum = 0, max = 0x80000000;

    for (int i = 0; i < length; i++) {
        sum += array[i];
        if (max < sum)
          max = sum;
        if (sum < 0)
          sum = 0;
    }
    return max;
}

