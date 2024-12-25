/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // 创建 dp 表 + 初始化
        vector<int> dp(n, 1);
        // 填表 + 更新结果
        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ret = max(dp[i], ret);
        }
        // 返回结果
        return ret;
    }
};
// @lc code=end
