/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        // 两种情况取最大值
        return max(nums[0] + rob1(nums, 2, n - 2), rob1(nums, 1, n - 1));
    }

    int rob1(vector<int> &nums, int left, int right)
    {
        // 处理边界情况
        if (left > right)
            return 0;
        int n = nums.size();
        // 创建 dp 表
        vector<int> f(n), g(n);
        // 初始化
        f[left] = nums[left];
        // 填表
        for (int i = left + 1; i <= right; i++)
        {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        // 返回结果
        return max(f[right], g[right]);
    }
};
// @lc code=end
