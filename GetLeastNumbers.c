/*
 * 给出一个数组，找出数组中最小的k个数
 * 算法1：用partition找到第k小的数，则该数之前的数就是所要的结果
 * 算法2：将数组中前k个数存入一个最大堆，遍历剩下的数，每个数跟堆中最大元素比较，如果比其小，就替换到最大堆中
 */

#include  <stdio.h>
#include  <stdlib.h>
#include  "Heap/Heap.h"

int Partition(int *array, int start, int end);

void GetLeastNumbers1(int *input, int input_length, int *output, int k)
{
    if (input == NULL || output == NULL || k > input_length || input_length <= 0 || k <= 0)
      return;

    int index, start = 0, end = input_length - 1;

    if (k != input_length) {
        while((index = Partition(input, start, end)) != k -1) {
            if (index < k - 1)
              start = index + 1;
            else
              end = index - 1;
        }
    }

    for (int i = 0; i < k; i++)
      output[i] = input[i];
}

void GetLeastNumbers2(int *input, int input_length, int *output, int k)
{
    if (input == NULL || output == NULL || k > input_length || input_length <= 0 || k <= 0)
      return;

    int i;
    //创建一个最大堆, 数组的第一个元素存堆中元素个数
    for (i = 0; i < k; i++)
      output[i + 1] = input[i];
    output[0] = k;
    BuildMaxHeap(output);
    //依次将数组中的数与堆中最大元素比较
    for (; i < input_length; i++) {
        if (input[i] < output[1]) {
            output[1] = input[i];
            MaxHeapify(output, 1);
        }
    }
}

