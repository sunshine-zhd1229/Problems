#include  <stdio.h>
#include  <stdlib.h>

extern int ErrorFlag;
#define IsLeaf(x, y)    (x) >= ((y) / 2 + 1) ? 1 : 0 
#define     HeapLength  10

void Switch (int *x, int *y)    
{
    (*x) ^= (*y); 
    (*y) ^= (*x); 
    (*x) ^= (*y);
}

//保持以Heap[index]为根的最大堆的性质，Heap[0]中存储最大堆中元素个数，假定以left、right为根的堆均满足最大堆性质
void MaxHeapify(int Heap[], int index)
{
    int left = index * 2, right = left + 1, largest = index;
    if (index <= 0 || index > Heap[0])
      return;
    if (left <= Heap[0] && Heap[left] > Heap[index])
      largest = left;
    if (right <= Heap[0] && Heap[right] > Heap[largest])
      largest = right;
    if (largest != index) {
        Switch(Heap + index, Heap + largest);
        MaxHeapify(Heap, largest);
    } 
}

//用循环实现保持最大堆性质
void MaxHeapifyLoop(int Heap[], int index)
{
    int left, right, largest;
    int i = index;
    while (!IsLeaf(i, Heap[0])) {
        left = 2 * i;
        right = left + 1;
        largest = i;

        if (Heap[left] > Heap[i])
          largest = left;
        if (right < Heap[0] && Heap[right] > Heap[largest])
          largest = right;
        if(largest != i) {
          Switch(Heap + i, Heap + largest);
          i = largest;
        } else
          break;
    }
}

//建最大堆, 参数错误返回0,否则返回1
int BuildMaxHeap(int Heap[])
{
    if (Heap == NULL || Heap[0] <= 0)
      return 0;
    int i;

    //从最后一个非叶子节点开始知道第一个节点，分别维护堆的性质
    for (i = Heap[0] >> 1; i > 0; i--)
        MaxHeapify(Heap, i);
    return 1;
}

//堆排序
void HeapSort(int Heap[])
{
    if (Heap == NULL || Heap[0] <= 0)
      return;
    int i;
    for (i = Heap[0]; i > 1; i--) {
        Switch(Heap + 1, Heap + Heap[0]);
        Heap[0]--;
        MaxHeapify(Heap, 1);
    }
}

//返回堆中最大的数
int HeapMaximum(int Heap[])
{
    ErrorFlag = 0;
    if (Heap == NULL || Heap[0] <= 0) {
        ErrorFlag = 1;
        return 0;
    }
    return Heap[1];
}

//从堆中删除最大的数
int HeapExtractMax(int Heap[])
{
    ErrorFlag = 0;
    if (Heap == NULL || Heap[0] <= 0) {
        ErrorFlag = 1;
        return 0;
    }

    int max;
    if (Heap[0] < 1) {
        printf("heap underflow\n");
        return -1;
    }
    max = Heap[1];
    Heap[1] = Heap[Heap[0]];
    Heap[0]--;
    MaxHeapify(Heap, 1);
    return max;
}

//增大给定点的值，则该值可能大于其父节点，因此与其父节点比较，维护最大堆性质
void HeapInceraseKey(int Heap[], int index, int key)
{
    if (Heap == NULL || Heap[0] <= 0)
      return;
    int parent, i = index;
    if (key <= Heap[index]) {
        printf("new key is smaller than old one\n");
        return;
    }

    Heap[index] = key;
    while (i > 1) {
        parent = i / 2; 
        if (Heap[parent] < Heap[i]) {
            Switch(Heap + parent, Heap + i);
            i = parent;
        }
        else
          break;
    }
}
