/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        // 预处理
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        // 创建 dp 表 + 初始化
        vector<int> dp(n, 1);
        // 填表 + 更新结果
        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            // 更新结果
            ret = max(ret, dp[i]);
        }
        // 返回结果
        return ret;
    }
};
// @lc code=end
