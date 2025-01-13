/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
#include <iostream>
using namespace std;

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // 如果链表为空
        if (head == nullptr)
            return nullptr;
        // 链表不为空
        ListNode *cur = head, *tail = nullptr;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = tail;
            tail = cur, cur = next;
        }
        return tail;
    }
};
// @lc code=end
