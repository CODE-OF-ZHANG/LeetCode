/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0, MaxCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                ++count;
            else
            {
                MaxCount = max(count, MaxCount);
                count = 0;
            }
        }
        // 防止最后一个元素是1, 且最长连续 1 的子数组可能出现在数组的末尾
        MaxCount = max(MaxCount, count);
        return MaxCount;
    }
};
// @lc code=end
