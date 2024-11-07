/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> f(n);
        vector<int> g(n);
        // 1. 预处理前缀积和后缀积数组 + 初始化
        f[0] = 1, g[n - 1] = 1;
        for (int i = 1; i < n; i++)
        {
            f[i] = f[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            g[i] = g[i + 1] * nums[i + 1];
        }
        // 2. 使用前缀积和后缀积数组
        vector<int> ret(n);
        for (int i = 0; i < n; i++)
        {
            ret[i] = f[i] * g[i];
        }
        return ret;
    }
};
// @lc code=end
