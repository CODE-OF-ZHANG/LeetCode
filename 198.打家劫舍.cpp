/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        // 处理边界情况
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        // 创建 dp 表
        vector<int> dp(n);
        // 初始化
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        // 填表
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        // 返回结果
        return dp[n - 1];
    }
};
// @lc code=end
