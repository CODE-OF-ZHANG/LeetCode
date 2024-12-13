/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        // 创建 dp 表
        vector<int> f(n), g(n);
        // 初始化
        f[0] = -prices[0];
        // 填表顺序 --> 从左往右, 两个表同时填
        for (int i = 1; i < n; i++)
        {
            f[i] = max(f[i - 1], g[i - 1] - prices[i]);
            g[i] = max(g[i - 1], f[i - 1] + prices[i] - fee);
        }
        // 确定返回值
        return g[n - 1];
    }
};
// @lc code=end
