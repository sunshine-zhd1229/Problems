/*
 * 输入两个链表，查找链表的首个公共节点
 * 解法：由于链表存在公共节点，则从首个公共节点开始，后续的节点都是重合的，即呈Y字型
 *       先遍历两个链表，得到长度差n，较长的链表先走n步，之后两个链表同时遍历，第一个相同的节点就是公共节点
 */

#include  <stdio.h>
#include  "List.h"

ListNode * FindFirstCommonNode(List list1, List list2)
{
    if (list1 == NULL || list2 == NULL)
        return NULL;

    ListNode *p1;
    ListNode *p2;
    
    //读链表长度
    int LengthOfList1 = 0, LengthOfList2 = 0;

    for (p1 = list1; p1 != NULL; p1 = p1->Next)
      LengthOfList1++;

    for (p2 = list2; p2 != NULL; p2 = p2->Next)
      LengthOfList2++;

    int diff;
    if (LengthOfList1 > LengthOfList2) {
        diff = LengthOfList1 - LengthOfList2;
        p1 = list1;
    } else {
        diff = LengthOfList2 - LengthOfList1;
        p1 = list2;
    }

    //长链表先走n步
    while (diff-- > 0)
      p1 = p1->Next;

    while (p1 != NULL && p1 != p2) {
        p1 = p1->Next;
        p2 = p2->Next;
    }

    return p1;
}
