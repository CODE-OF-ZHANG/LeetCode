/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // 创建 dp 表 + 初始化
        vector<int> len(n, 1), count(n, 1);
        // 填表 + 更新结果
        int retlen = 1, retcount = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (len[j] + 1 == len[i])
                        count[i] += count[j];
                    else if (len[j] + 1 > len[i])
                        len[i] = len[j] + 1, count[i] = count[j];
                }
            }
            // 更新结果
            if (retlen == len[i])
                retcount += count[i];
            else if (retlen < len[i])
                retlen = len[i], retcount = count[i];
        }
        // 返回结果
        return retcount;
    }
};
// @lc code=end
