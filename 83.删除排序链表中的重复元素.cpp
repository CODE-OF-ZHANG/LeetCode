/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
#include<iostream>
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 如果链表为空, 直接返回
        if(head == nullptr)
            return head;
        // 链表不为空
        ListNode *cur = head;
        while (cur->next != nullptr)
        {
            // 当前节点的值与下一个节点的值相等
            if(cur->val == cur->next->val)
                cur->next = cur->next->next;
            // 值不相等的话就继续往后遍历
            else
                cur = cur->next;
        }
        // 返回结果
        return head;
    }
};
// @lc code=end

