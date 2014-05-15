/*
 * 输入一个整数，打印出和为该整数的所有连续自然数序列
 */

#include  <stdio.h>

//打印从start开始的num个数
void PrintSequence(int start, int num)
{
    while(num--) {
        printf("%d ", start++);
    }
    printf("\n");
}

void GetSequence(int sum)
{
    if (sum <= 2)
      return;
    int i, step, tail, start;
    if (sum & 1) {
        i = 2;
        step = 2;
        tail = 1;
    } else {
        i = 3;
        step = 1;
        tail = 3;
    }

    while ((start = (sum - tail) / i) >= 1) {
        if ((sum - tail) % i == 0)
          PrintSequence(start, i);

        if (i == 2)
          i++;
        else
          i += step;
        tail = i * (i - 1) / 2;
    }
}

