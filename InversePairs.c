/*
 * 利用归并排序求数组中逆序数
 */

#include  <stdio.h>

//返回逆序数的归并
int MergeSort(int* orgin, int* copy, int start, int end)
{
    if (start == end)
        return 0;

    int mid = (start + end) >> 1;
    int count = MergeSort(copy, orgin, start, mid);   //前半部分的逆序数
    count += MergeSort(copy, orgin, mid + 1, end);    //后半部分的逆序数
    
    int i, j, index;
    for (i = start, index = start, j = mid + 1; i <= mid && j <= end;)
    {
        if (orgin[i] > orgin[j]) {
            //存在逆序
            copy[index++] = orgin[j++];
            count += mid - i + 1;   //orgin[i]后的数都比orgin[j]大，因此都是逆序
        } else {
            copy[index++] = orgin[i++];
        }
    }

    while (i <= mid)
      copy[index++] = orgin[i++];
    while (j <= end)
      copy[index++] = orgin[j++];

    return count;
}

int InversePairs(int *data, int length)
{
    if (data == NULL || length <= 0)
      return -1;

    int copy[length];   //归并排序用的辅助存储数组
    for (int i = 0; i < length; i++)
      copy[i] = data[i];

    int count = MergeSort(data, copy, 0, length - 1);   //归并排序返回逆序数

    return count;
}

