/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // 创建 dp 表
        vector<vector<int>> dp(n, vector<int>(3));
        // 初始化
        dp[0][0] = -prices[0];
        // 填表 --> 从左往右填, 三个表同时填
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = dp[i - 1][0] + prices[i];
        }
        // 返回结果
        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};
// @lc code=end
