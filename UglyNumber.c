/*
 * 求第N个丑数
 * 解法：
 *       一个数如果是丑数，则一定是某个丑数与2或3或5的乘积
 *       因此只要用数组array记录找到的丑数，分别乘2,3,5就可以得到其后的丑数，并保持这个数组有序，直到计算到第N个丑数为止
 *       设第k个丑数是M，则前k个丑数中，存在下标为index2的丑数，使multi2 = array[index2] * 2 > M，同理存在index3、index5使multi3 = array[index3] * 3 > M
 *       multi5 = array[index5] * 5 > M。因此第k + 1个整数M'就是multi2, multi3, multi5中最小的一个。
 */

#include  <stdio.h>

int NthUglyNumber(int n)
{
    if (n <= 0)
      return -1;
    
    int UglyNumbers[n];     //用于存丑数的数组
    UglyNumbers[0] = 1;

    int nextUgly = 1,       //下一个丑数的下标
        index2 = 0,         //用来乘以2的丑数的下标
        index3 = 0,         //用来乘以3的丑数的下标
        index5 = 0;         //用来乘以5的丑数的下标
    
    int Multi2 = UglyNumbers[index2] * 2,
        Multi3 = UglyNumbers[index3] * 3,
        Multi5 = UglyNumbers[index5] * 5;

    while (nextUgly < n) {
        //下一个丑数为三个乘积中的最小值
        int min = Multi2 < Multi3 ? Multi2 : Multi3;
        min = min < Multi5 ? min : Multi5; 
        UglyNumbers[nextUgly] = min;
        
        //找到大于当前丑数的下一个候选值
        while(Multi2 <= min)
          Multi2 = UglyNumbers[++index2] * 2;
        while(Multi3 <= min)
          Multi3 = UglyNumbers[++index3] * 3;
        while(Multi5 <= min)
          Multi5 = UglyNumbers[++index5] * 5;
        
        nextUgly++;
    }
    return UglyNumbers[n - 1];
}

