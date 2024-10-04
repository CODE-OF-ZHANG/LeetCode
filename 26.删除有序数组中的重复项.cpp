/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)  return 0;
        sort(nums.begin(), nums.end());
        int i = 1;  // 慢指针
        for(int j = 1; j < nums.size(); j++){
            if(nums[i - 1] != nums[j])  {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
// @lc code=end

