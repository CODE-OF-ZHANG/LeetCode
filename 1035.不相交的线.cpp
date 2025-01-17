/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        // 创建 dp 表
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 填表
        for (int i = 1; i <= m; i++)
        {
            // 下标的映射关系
            int num1 = nums1[i - 1];
            for (int j = 1; j <= n; j++)
            {
                int num2 = nums2[j - 1];
                if (num1 == num2)
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // 返回结果
        return dp[m][n];
    }
};
// @lc code=end
