/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        // 创建 dp 表 + 初始化
        vector<int> dp(n + 1);
        // 填表 --> 从左往右填表
        int ret = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
            ret = max(ret, dp[i]);
        }
        // 返回结果
        return ret;
    }
};
// @lc code=end
