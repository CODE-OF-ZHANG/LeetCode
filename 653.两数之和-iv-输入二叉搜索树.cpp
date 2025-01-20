/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
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
#include <unordered_set>
using namespace std;

class Solution
{
    // 创建 hash 表
    unordered_set<int> hash;

public:
    bool findTarget(TreeNode *root, int k)
    {
        // 如果树为空
        if (root == nullptr)
            return false;
        // 寻找 k - root->val
        if (hash.count(k - root->val))
            return true;
        hash.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
// @lc code=end
