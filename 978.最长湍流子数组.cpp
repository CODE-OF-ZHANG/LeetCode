/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int n = arr.size();
        // 创建 dp 表 + 初始化
        vector<int> f(n, 1), g(n, 1);
        // 填表 + 更新结果
        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
                f[i] = g[i - 1] + 1;
            else if (arr[i] < arr[i - 1])
                g[i] = f[i - 1] + 1;
            ret = max(ret, max(f[i], g[i]));
        }
        // 返回结果
        return ret;
    }
};
// @lc code=end
