/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        // 创建 dp 表 + 初始化
        vector<int> dp(n);
        // 填表 --> 从左往右填 + 更新结果
        int sum = 0;
        for (int i = 2; i < n; i++)
        {
            dp[i] = nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? dp[i - 1] + 1 : 0;
            sum += dp[i];
        }
        // 返回结果
        return sum;
    }
};
// @lc code=end
