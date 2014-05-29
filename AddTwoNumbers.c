/*
 * 位运算做加法
 */

#include  <stdio.h>

long Add(int a, int b)
{
    long sum, carry;
    do {
        sum = a ^ b;
        carry = (a & b) << 1;
        a = sum;
        b = carry;
    } while (carry != 0);
    return sum;
}

