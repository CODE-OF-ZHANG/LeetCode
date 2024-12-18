/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        // 创建 dp 表
        vector<int> f(n + 1), g(n + 1);
        // 初始化
        f[0] = g[0] = 1;
        // 填表
        int ret = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            int x = nums[i - 1], y = f[i - 1] * nums[i - 1], z = g[i - 1] * nums[i - 1];
            f[i] = max(x, max(y, z));
            g[i] = min(x, min(y, z));
            // 更新结果
            ret = max(ret, f[i]);
        }
        // 返回结果
        return ret;
    }
};
// @lc code=end
