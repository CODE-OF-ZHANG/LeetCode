/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        struct ListNode *cur1 = list1, *cur2 = list2;
        struct ListNode *head = NULL, *tail = NULL;
        while (cur1 && cur2)
        {
            if (cur1->val < cur2->val)
            {
                if (head == NULL)
                {
                    head = tail = cur1;
                }
                else
                {
                    tail->next = cur1;
                    tail = tail->next;
                }
                cur1 = cur1->next;
            }
            else
            {
                if (head == NULL)
                {
                    head = tail = cur2;
                }
                else
                {
                    tail->next = cur2;
                    tail = tail->next;
                }
                cur2 = cur2->next;
            }
        }
        if (cur1)
        {
            tail->next = cur1;
        }
        if (cur2)
        {
            tail->next = cur2;
        }
        return head;
    }
};
// @lc code=end

