/*
 * @lc app=leetcode.cn id=1567 lang=cpp
 *
 * [1567] 乘积为正数的最长子数组长度
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int n = nums.size();
        // 创建 dp 表 + 初始化
        vector<int> f(n + 1), g(n + 1);
        // 填表
        int ret = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (nums[i - 1] > 0)
            {
                f[i] = f[i - 1] + 1;
                g[i] = g[i - 1] == 0 ? 0 : g[i - 1] + 1;
            }
            else if (nums[i - 1] < 0)
            {
                f[i] = g[i - 1] == 0 ? 0 : g[i - 1] + 1;
                g[i] = f[i - 1] + 1;
            }
            ret = max(ret, f[i]);
        }
        // 返回结果
        return ret;
    }
};
// @lc code=end
