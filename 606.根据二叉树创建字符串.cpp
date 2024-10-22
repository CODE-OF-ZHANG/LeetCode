/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
class Solution
{
public:
    string tree2str(TreeNode *root)
    {
        // 空树
        if (root == nullptr)
            return "";
        string str = to_string(root->val);
        // 左不为空且右不为空；左不为空或者右不为空；左为空，右不为空，括号都不能省略
        if (root->left || root->right)
        {
            str += '(';
            str += tree2str(root->left);
            str += ')';
        }
        if (root->right)
        {
            str += '(';
            str += tree2str(root->right);
            str += ')';
        }
        return str;
    }
};
// @lc code=end

