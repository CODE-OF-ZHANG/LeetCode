/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
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
                v.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            // 依次访问左路结点的右子树
            TreeNode *top = st.top();
            st.pop();

            // 子问题的方式访问右子树
            cur = top->right;
        }
        return v;
    }
};
// @lc code=end

