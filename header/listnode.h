#ifndef LISTNODE_H_INCLUDED
#define LISTNODE_H_INCLUDED

#include "myheader.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 如果形参是 int arr[], len始终是1.
template<class T>
ListNode* convertArray(T& arr)
{
//    int len = sizeof(arr) / sizeof(arr[0]);

    int len = 0;
//    if (typeid(vector<int>).name() == typeid(arr).name())
//        len = arr.size();             // 不行，传入数组时，编译失败，数组没有size方法。
//    else
        len = sizeof(arr) / sizeof(arr[0]);

    struct ListNode head(-1);
    struct ListNode* p = &head;
    for (int i = 0; i < len; i++)
    {
//        ListNode n1(arr[i]);      // 这个会导致后续的ListNode都是同一个。应该是声明格式的问题？
//        n1.next = NULL;
//        p->next = &n1;
        ListNode* p1 = new ListNode(arr[i]);
        p1->next = NULL;
        p->next = p1;
        p = p->next;
    }
    return head.next;
}

void showListNode(ListNode* n)
{
    while(n != NULL)
    {
        cout<<n->val<<", ";
        n = n->next;
    }
    cout<<endl;
}

void deleteListNode(ListNode* n)
{
    while (n != nullptr)
    {
        ListNode* t2 = n->next;
        delete n;
        n = t2;
    }
}

#endif // LISTNODE_H_INCLUDED
