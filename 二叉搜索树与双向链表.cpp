
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    // 中序
    void InOrder(TreeNode *cur, TreeNode *&prev)
    {
        if (cur == nullptr)
            return;
        InOrder(cur->left, prev);
        // 当前left指向前一个
        cur->left = prev;
        if (prev)
            prev->right = cur;
        prev = cur;

        InOrder(cur->right, prev);
    }

    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        TreeNode *prev = nullptr;
        InOrder(pRootOfTree, prev);
        TreeNode *head = pRootOfTree;
        while (head && head->left)
        {
            head = head->left;
        }
        return head;
    }
};
