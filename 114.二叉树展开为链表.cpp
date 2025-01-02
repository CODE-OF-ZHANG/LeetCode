/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    void prpreorderTraversal(TreeNode *root, vector<TreeNode *> &l)
    {
        if (root != nullptr)
        {
            l.push_back(root);
            prpreorderTraversal(root->left, l);
            prpreorderTraversal(root->right, l);
        }
    }

    void flatten(TreeNode *root)
    {
        vector<TreeNode *> l;
        prpreorderTraversal(root, l);
        int n = l.size();
        for (int i = 1; i < n; i++)
        {
            TreeNode *prev = l.at(i - 1), *curr = l.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }
};
// @lc code=end

