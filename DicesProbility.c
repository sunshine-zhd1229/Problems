/*
 *  把n个骰子扔在地上，所有骰子朝上一面的点数之和为S。输入n，打印出S的所有可能的值出现的概率。  
 *  输入：输入包括一个整数N(1<=N<=1000)，代表有N个骰子。  
 *  解法：设有k个骰子，则s的可能取值有k-6k，设f(n)为s=n出现的次数
 *        当有k+1个骰子时，f'(n) 为s=n出现的次数，此时按第k+1个骰子出现的值为1-6而分成6种情况：
 *              第k+1个骰子为1时，前k个骰子的和应为n-1,显然前k个骰子和为n-1出现的次数为f(n-1)，同理
 *              第k+1个骰子为2时，前k个骰子的和应为n-2,出现的次数为f(n-2)
 *              .
 *              .
 *              .
 *              第k+1个骰子为6时，前k个骰子的和为n-6,出现的次数为f(n-6)
 *              因此f'(n) = f(n-1) + f(n - 2) + f(n - 3) + f(n - 4) + f(n - 5) + f(n - 6)
 *              可推得 f'(n + 1) = f'(n) + f(n) - f(n - 6)
 */

#include  <stdio.h>
#include  <string.h>
#include  <math.h>

void PrintProbability(int num)
{
    if (num <= 0)
      return;

    int times[2][num * 6 + 1];
    memset(times, 0, sizeof(int) * 2 * (num * 6 + 1));
    
    int last_sum_min = 0, last_sum_max = 0, sum_min, sum_max, current_array = 0;

    for (int i = 1; i <= num; i++)
    {
        sum_min = i;
        sum_max = 6 * i;
        times[current_array][sum_min] = 1;

        for (int j = sum_min + 1; j <= sum_max; j++) {
            times[current_array][j] = times[current_array][j - 1];

            if ((j -1) >= last_sum_min && (j - 1) <= last_sum_max)
                times[current_array][j] += times[1 - current_array][j - 1];
            if ((j - 7) >= last_sum_min && (j - 7) <= (last_sum_max))
                times[current_array][j] -= times[1 - current_array][j - 7];
        }

        last_sum_min = sum_min;
        last_sum_max = sum_max;

        times[1 - current_array][i] = 0;
        times[1 - current_array][i - 1] = 0;
        current_array = 1 - current_array;
    }

    double total = pow(6, num);

    for (int i = last_sum_min; i <= last_sum_max; i++)
      printf("%d: %.3f\n", i, times[1 - current_array][i] / total);
}

