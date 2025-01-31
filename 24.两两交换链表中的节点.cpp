/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        // 没有节点或者只有一个节点
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        // 拥有两个以上的节点
        ListNode *newhead = head->next;
        head->next = swapPairs(newhead->next);
        newhead->next = head;
        return newhead;
    }
};
// @lc code=end
