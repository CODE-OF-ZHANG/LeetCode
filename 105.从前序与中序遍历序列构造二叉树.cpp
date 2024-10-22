/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *_buildTree(vector<int> &preorder, vector<int> &inorder,
                        int &prei, int inbegin, int inend)
    {
        if (inbegin > inend)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[prei]);
        int rooti = inbegin;
        while (rooti <= inend)
        {
            if (preorder[prei] == inorder[rooti])
                break;

            ++rooti;
        }
        ++prei;
        root->left = _buildTree(preorder, inorder, prei, inbegin, rooti - 1);
        root->right = _buildTree(preorder, inorder, prei, rooti + 1, inend);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int i = 0;
        return _buildTree(preorder, inorder, i, 0, inorder.size() - 1);
    }
};

// @lc code=end
