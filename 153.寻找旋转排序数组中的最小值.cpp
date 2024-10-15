/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int n = nums[right];
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] > n)  left = mid + 1;
            else right = mid;
        }
        return nums[right];
    }
};

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         return nums[0];
//     }
// };
// @lc code=end

