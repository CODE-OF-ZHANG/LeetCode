/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        const int N = 10001;
        // 数据预处理
        int arr[N] = {0};
        for (const auto &e : nums)
            arr[e] += e;
        // 创建 dp 表
        vector<int> f(N), g(N);
        // 初始化
        f[0] = arr[0], g[0] = 0;
        // 从左往右进行填表, 两个表同时填
        for (int i = 1; i < 10001; i++)
        {
            f[i] = g[i - 1] + arr[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        // 返回结果
        return max(f[N - 1], g[N - 1]);
    }
};
// @lc code=end
