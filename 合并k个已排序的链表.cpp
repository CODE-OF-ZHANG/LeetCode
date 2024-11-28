/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param lists ListNode类vector
     * @return ListNode类
     */
    ListNode *merges(ListNode *phead1, ListNode *phead2)
    {
        if (phead1 == nullptr)
            return phead2;
        if (phead2 == nullptr)
            return phead1;
        // 头结点
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        // 两个链表都不为空
        while (phead1 && phead2)
        {
            if (phead1->val <= phead2->val)
            {
                cur->next = phead1;
                phead1 = phead1->next;
            }
            else
            {
                cur->next = phead2;
                phead2 = phead2->next;
            }
            cur = cur->next;
        }
        // 那个链表还有剩
        if (phead1)
            cur->next = phead1;
        else
            cur->next = phead2;
        return head->next;
    }

    ListNode *dividemerges(vector<ListNode *> &lists, int left, int right)
    {
        if (left > right)
            return nullptr;
        else if (left == right)
            return lists[left];
        int mid = (left + right) / 2;
        return merges(dividemerges(lists, left, mid), dividemerges(lists, mid + 1, right));
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // write code here
        return dividemerges(lists, 0, lists.size() - 1);
    }
};
