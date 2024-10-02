/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        for(auto a : nums)  sum += a;
        int target = sum - x;
        if (target < 0)  return -1;
        int ret = -1;
        for(int left = 0, right = 0, tmp = 0; right < n; right++) {
            tmp += nums[right];  // 进窗口
            while(tmp > target)  tmp -= nums[left++];  // 出窗口
            if(tmp == target)  ret = max(ret, right - left + 1);
        }
        if (ret == -1)  return ret;
        else return nums.size() - ret;
    }
};
// @lc code=end

