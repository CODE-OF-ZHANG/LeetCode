/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        // 创建 dp 表
        vector<int> f(n + 1), g(n + 1);
        // 初始化
        int fmax = INT_MIN, gmin = INT_MAX, sum = 0;
        // 填表
        for (int i = 1; i <= n; i++)
        {
            int x = nums[i - 1];
            f[i] = max(x, x + f[i - 1]);
            fmax = max(fmax, f[i]);
            g[i] = min(x, x + g[i - 1]);
            gmin = min(gmin, g[i]);
            sum += x;
        }
        // 返回结果
        return sum == gmin ? fmax : max(fmax, sum - gmin);
    }
};
// @lc code=end
