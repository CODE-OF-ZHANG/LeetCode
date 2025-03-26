/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int level = 0;
        TreeNode *node = root;
        while (node->left != nullptr)
        {
            level++;
            node = node->left;
        }
        int low = 1 << level, higt = (1 << (level + 1)) - 1;
        while (low < higt)
        {
            int mid = (higt - low + 1) / 2 + low;
            if (exists(root, level, mid))
                low = mid;
            else
                higt = mid - 1;
        }
        return low;
    }

    bool exists(TreeNode *root, int level, int k)
    {
        int bits = 1 << (level - 1);
        TreeNode *node = root;
        while (node != nullptr && bits > 0)
        {
            if (!(bits & k))
                node = node->left;
            else
                node = node->right;
            bits >>= 1;
        }
        return node != nullptr;
    }
};
// @lc code=end
