/*
 * 输入一个整数n，求从1到n所有整数的十进制表示中1出现的次数
 * 解法：分别求每一位是1时，不同的数有多少个(f(n))
 *       设当前要求的位是右数第k位，当前位上的值为current，
 *       当前位前面的高位数为higher，后面的低位数为lower。
 *       则有公式：
 *                f(n) = higher * (10 ^ (k - 1)),             current = 0
 *                       higher * (10 ^ (k - 1)) + lower + 1, current = 1
 *                       (higher + 1) * (10 ^ (k -1)),        current > 1
 * 
 *       注：10 ^ (k - 1)表示10的k - 1次方
 */

#include  <stdio.h>

int NumberOf1Between1AndN(unsigned int n)
{
    if (n == 0)
      return -1;
    
    int current = 0, higher = 0, lower = 0, k = 1, counter = 0;
    
    int temp;
    while ((temp = n / k) != 0)
    {
        current = temp % 10;    //当前位的数字
        higher = temp / 10;     //当前位之前的高位数
        lower = n % k;          //当前位之后的低位数
        
        switch(current) {
            case 0:
                counter += higher * k;
                break;
            case 1:
                counter += higher * k + lower + 1;
                break;
            default:
                counter += (higher + 1) * k;
        }

        k = k * 10;
    }
    return counter;
}

