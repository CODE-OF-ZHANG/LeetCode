/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        // 处理特殊情况
        if (n <= 2)
            return n;
        // 快慢双指针
        int slow = 2, fast = 2;
        while (fast < n)
        {
            if (nums[slow - 2] != nums[fast])
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
// @lc code=end
