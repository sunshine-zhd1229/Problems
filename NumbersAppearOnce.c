/*
 * 数组中有两个数分别出现1次，其余数均出现两次，找到出现一次的数
 * 解法：如果数组中仅有一个数出现1次，则将数组从头到尾异或就可得到出现一次的数
 *       因此将数组分成两个，每个数组中包含一个出现1次的数
 *       对原数组中所有数进行异或，结果为两个只出现一次的数的异或值，在该值中找到一个为1的位，按该位是否为1将数组分成两个，即可将出现一次的数分到两个数组里
 */

#include  <stdio.h>

//找到第一个位1的位，返回值该位为1,其余位为0
int FindFirstBit1(int value)
{
    int result = 1;
    for (int i = 0; i < 8 * sizeof(int); i++)
    {
        if (value & result)
          return result;
        result <<= 1;
    }
    return 0;
}

//找到数字返回0, 输入错误返回-1
int FindNumbersAppearOnce(int *numbers, int length, int *num1, int *num2)
{
    if (numbers == NULL || length < 2)
      return -1;
    
    int OrOfAll = 0;
    for (int i = 0; i < length; i++)
      OrOfAll ^= numbers[i];
    
    int bitmask = FindFirstBit1(OrOfAll);
    //说明异或结果中没有为1的位，即输入中数字没有两个不同数
    if (!bitmask)
        return -1;

    *num1 = 0, *num2 = 0;
    for (int i = 0; i < length; i++)
      if (numbers[i] & bitmask)
        *num1 ^= numbers[i];
      else
        *num2 ^= numbers[i];
    return 0;
}

