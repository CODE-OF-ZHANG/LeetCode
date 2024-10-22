/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    // 查找路径
    bool FindPath(TreeNode *root, TreeNode *x, stack<TreeNode *> &path)
    {
        if (root == nullptr)
            return false;
        // 入栈
        path.push(root);

        if (root == x)
            return true;

        if (FindPath(root->left, x, path))
            return true;

        if (FindPath(root->right, x, path))
            return true;
        // 不是我们要找的结点，直接pop
        path.pop();
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        stack<TreeNode *> pPath, qPath;
        FindPath(root, p, pPath);
        FindPath(root, q, qPath);

        // 让元素多的栈先走，直到两个栈的元素个数相等
        while (pPath.size() > qPath.size())
        {
            pPath.pop();
        }

        while (pPath.size() < qPath.size())
        {
            qPath.pop();
        }

        // 依次判断元素想不想等(找交点), 相等的即为公共祖先
        while (pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }
        return pPath.top();
    }
};
// @lc code=end

