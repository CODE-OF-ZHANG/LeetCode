/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
#include <iostream>
using namespace std;

class Solution
{
    int ans;
    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        ans = max(ans, l + r + 1);
        return max(l, r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};
// @lc code=end
