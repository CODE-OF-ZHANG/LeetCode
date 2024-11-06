/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> f(n), g(n);
        // 1. 预处理前缀和数组
        for (int i = 1; i < n; i++)
        {
            f[i] = f[i - 1] + nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            g[i] = g[i + 1] + nums[i + 1];
        }
        // 2. 使用前缀和数组
        for (int i = 0; i < n; i++)
        {
            if (f[i] == g[i])
                return i;
        }
        return -1;
    }
};
// @lc code=end
