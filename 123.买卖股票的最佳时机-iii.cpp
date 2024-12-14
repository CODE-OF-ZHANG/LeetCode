/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 最值
    const int INF = 0x3f3f3f3f;
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // 创建 dp 表
        vector<vector<int>> f(n, vector<int>(3, -INF)), g(n, vector<int>(3, -INF));
        // 初始化
        f[0][0] = -prices[0], g[0][0] = 0;
        // 填表
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                g[i][j] = g[i - 1][j];
                // 如果下面这种转态存在
                if (j >= 1)
                    g[i][j] = max(g[i - 1][j], f[i - 1][j - 1] + prices[i]);
            }
        }
        // 找到最后一行的最大值
        int ret = 0;
        for (int j = 0; j < 3; j++)
        {
            ret = max(ret, g[n - 1][j]);
        }
        return ret;
    }
};
// @lc code=end
