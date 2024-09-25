/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        // 排序
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; )
        {
            int left = i + 1, right = n - 1, rnum = -nums[i];
            // 左右双指针
            while(left < right)
            {
                if(nums[left] + nums[right] > rnum) right--;
                else if(nums[left] + nums[right] < rnum) left++;
                else{
                    ret.push_back({nums[i], nums[left], nums[right]});
                    // left 与 right 去重
                    left++, right--;
                    while(left < right && nums[left] == nums[left - 1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;
                }
            }
            // 去重i
            ++i;
            while(i < n && nums[i] == nums[i - 1]) i++;
        }
        return ret;
    }
};
// @lc code=end

