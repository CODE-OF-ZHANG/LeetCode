/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // 左右双指针, 采用三指针策略
        int left = -1, right = nums.size();
        for (int i = 0; i < right;)
        {
            // 假设当前位置的值为0, left + 1 与 i 这个位置的值进行交换, i++
            if (nums[i] == 0)
                swap(nums[++left], nums[i++]);
            // 当前位置为1, 直接i++即可
            else if (nums[i] == 1)
                i++;
            // 当前位置的值为2, i 与 --right位置的值进行交换, i不变
            else
                swap(nums[--right], nums[i]);
        }
    }
};
// @lc code=end
