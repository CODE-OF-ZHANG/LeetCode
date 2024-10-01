/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, zero = 0, n = nums.size();
        int ret = 0;
        while(right < n){
            if(nums[right++] == 0)  zero++;
            while(zero > k)
                if(nums[left++] == 0)  zero--;
            ret = max(ret, right - left);
        }
        return ret;
    }
};
// @lc code=end

