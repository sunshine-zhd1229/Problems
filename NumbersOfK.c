/*
 * 在有序数组中找到k出现的次数
 */
#include  <stdio.h>
//二分查找，找到第一个k的位置
int GetFistK(int *array, int length, int k, int start, int end)
{
    if (start > end)
      return -1;

    int mid = (start + end) >> 1;
    if (array[mid] < k)
      start = mid + 1;
    else if (array[mid] > k)
      end = mid - 1;
    else {
        if (mid == 0 || array[mid - 1] != k)
          return mid;
        else
          end = mid - 1;
    }

    return GetFistK(array, length, k, start, end);
}

//二分查找最后一个k
int GetLastK(int *array, int length, int k , int start, int end)
{
    if (start > end)
      return -1;

    int mid = (start + end) >> 1;
    if (array[mid] < k)
      start = mid + 1;
    else if (array[mid] > k)
      end = mid - 1;
    else {
        if (mid == length - 1 || array[mid + 1] != k)
          return mid;
        else
          start = mid + 1;
    }

    return GetLastK(array, length, k, start, end);
}

int GetNumberOfK(int *array, int length, int k)
{
    if (array == 0 || length <= 0)
      return -1;

    int first = GetFistK(array, length, k, 0, length - 1);
    
    if (first == -1)
      return 0;
    int last = GetLastK(array, length, k, first, length - 1);

    return last - first + 1;
}

