#include  <time.h>
#include  <stdlib.h>

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//在start和end之间随机选取一个数与array[end]交换
void RandSwap(int *array, int start, int end)
{
    srand(time(NULL));
    int i = (rand() % (end - start)) + start;
    Swap(array + i, array + end);
}

int Partition(int *array, int start, int end) 
{
    if(start == end)
      return start;

    //数组中随机挑选一个数与最后一个数交换
    RandSwap(array, start, end);
    //i指向最后一个小于array[end]的数
    int i = start - 1, j = start;
    for(; j < end; j++) {
        if (array[j] < array[end]) {
            i++;
            if (i != j) {
                Swap(array + i, array + j);
            }
        }    
    }
    i++;
    Swap(array + i, array + j);
    return i;
}
