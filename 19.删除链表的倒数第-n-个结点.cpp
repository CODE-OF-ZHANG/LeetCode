/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr){} 
//     ListNode(int x) : val(x), next(nullptr){} 
//     ListNode(int x, ListNode *next) : val(x), next(next){}
// };
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int getLenght(ListNode *head)
    {
        int lenght = 0;
        while (head)
        {
            ++lenght;
            head = head->next;
        }
        return lenght;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        int length = getLenght(head);
        ListNode *cur = dummy;
        for (int i = 1; i < length - n + 1; ++i)
        {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
// @lc code=end

