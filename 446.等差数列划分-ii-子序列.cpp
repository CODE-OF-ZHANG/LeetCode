/*
 * @lc app=leetcode.cn id=446 lang=cpp
 *
 * [446] 等差数列划分 II - 子序列
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        // 算法优化
        unordered_map<long long, vector<int>> hash;
        for (int i = 0; i < n; i++)
            hash[nums[i]].push_back(i);
        // 创建 dp 表
        vector<vector<int>> dp(n, vector<int>(n));
        // 填表 + 更新结果
        int sum = 0;
        for (int j = 2; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                long long a = (long long)2 * nums[i] - nums[j];
                if (hash.count(a))
                {
                    for (const auto &k : hash[a])
                    {
                        if (k < i)
                            dp[i][j] += dp[k][i] + 1;
                    }
                }
                // 更新结果
                sum += dp[i][j];
            }
        }
        // 返回结果
        return sum;
    }
};
// @lc code=end
