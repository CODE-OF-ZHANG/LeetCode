/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *prev = nullptr;
        TreeNode *cur = nullptr;
        if (root)
            cur = root;

        vector<int> v;
        while (cur || !st.empty())
        {
            // 访问一棵树的开始
            // 1、先访问左路结点，左入结点入栈，后续一次访问左路结点的右子树
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode *top = st.top();
            // 一个结点的右子树为空或者上一个访问的结点是右子树的根
            // 即可以访问右子树
            if (top->right == nullptr || top->right == prev)
            {
                prev = top;
                v.push_back(top->val);
                st.pop();
            }
            else
            {
                cur = top->right;
            }
        }
        return v;
    }
};
// @lc code=end

