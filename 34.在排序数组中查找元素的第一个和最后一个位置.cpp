/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> ret;
        if(nums.size() == 0)  return {-1, -1};
        // 求左端点
        while(left < right)  // 不能等于，等于会造成死循环
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if(nums[right] == target)  ret.push_back(right);
        else ret.push_back(-1);
        // 求右端点
        left = 0, right = nums.size() - 1;
        while(left < right)  // 不能等于，等于会造成死循环
        {
            int mid = left + (right - left + 1) / 2;
            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }
        if(nums[left] == target)  ret.push_back(left);
        else ret.push_back(-1);
        return ret;
    }
};

// @lc code=end

