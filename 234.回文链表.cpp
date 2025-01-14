/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode *head)
    {
        // 复制链表值到数组列表中
        vector<int> vals;
        while (head != nullptr)
        {
            // 将链表中的值拷贝到数组中
            vals.emplace_back(head->val);
            head = head->next;
        }
        // 遍历数组, 数组回文则链表回文
        for (int i = 0, j = (int)vals.size() - 1; i < j; i++, j--)
        {
            if (vals[i] != vals[j])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
