/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 最低成本, 最高利润
        int cost = INT_MAX, profit = 0;
        for (const auto &price : prices)
        {
            cost = min(cost, price);
            profit = max(profit, price - cost);
        }
        return profit;
    }
};
// @lc code=end
