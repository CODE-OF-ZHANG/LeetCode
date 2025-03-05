/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> s;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i > k)
                s.erase(nums[i - k - 1]);
            if (s.count(nums[i]))
                return true;
            s.emplace(nums[i]);
        }
        return false;
    }
};
// @lc code=end
