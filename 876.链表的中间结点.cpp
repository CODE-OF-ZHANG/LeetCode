/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
#include <vector>
using namespace std;

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        vector<ListNode *> newnode = {head};
        while (newnode.back()->next != nullptr)
        {
            newnode.push_back(newnode.back()->next);
        }
        return newnode[newnode.size() / 2];
    }
};
// @lc code=end
