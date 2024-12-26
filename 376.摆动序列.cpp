/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

// 解法一: 二分
// class Solution
// {
// public:
//     int wiggleMaxLength(vector<int> &nums)
//     {
//         int n = nums.size(), left = 0, ret = 0;
//         for (int i = 0; i < n - 1; i++)
//         {
//             // 找到波峰和波谷
//             int right = nums[i + 1] - nums[i];
//             // 值相等的话跳过, 只需考虑左右两边的值即可
//             if (right == 0)
//                 continue;
//             // 找极值
//             if (right * left <= 0)
//                 ret++;
//             // 更新left的位置
//             left = right;
//         }
//         // 添加最后一个值
//         return ret + 1;
//     }
// };

// 解法二: 动态规划解法
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        // 创建 dp 表 + 初始化
        vector<int> f(n, 1), g(n, 1);
        // 填表 --> 从左往右, 两个表一起填 + 更新结果
        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    f[i] = max(g[j] + 1, f[i]);
                else if (nums[i] < nums[j])
                    g[i] = max(f[j] + 1, g[i]);
            }
            ret = max(ret, max(f[i], g[i]));
        }
        // 返回结果
        return ret;
    }
};
// @lc code=end
