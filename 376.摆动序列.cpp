/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size(), left = 0, ret = 0;
        for (int i = 0; i < n - 1; i++)
        {
            // 找到波峰和波谷
            int right = nums[i + 1] - nums[i];
            // 值相等的话跳过, 只需考虑左右两边的值即可
            if (right == 0)
                continue;
            // 找极值
            if (right * left <= 0)
                ret++;
            // 更新left的位置
            left = right;
        }
        // 添加最后一个值
        return ret + 1;
    }
};
// @lc code=end
