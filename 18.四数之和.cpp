/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int n = nums.size();
        // 先固定第一个数i
        for(int i = 0; i < n; ){
            // 固定第二个数j
            for(int j = i + 1; j < n; ){
                // 利用双指针解决问题
                int left = j + 1, right = n - 1;
                long long rnum = (long long)target - nums[i] - nums[j];  // 处理数据溢出问题
                while(left < right){
                    if(nums[left] + nums[right] > rnum) right--;
                    else if(nums[left] + nums[right] < rnum) left++;
                    else{
                        ret.push_back({nums[i], nums[j], nums[left++], nums[right--]});
                        // 对 left 和 right 进行去重操作
                        while(left < right && nums[left] == nums[left - 1])  left++;
                        while(left < right && nums[right] == nums[right + 1])  right--;
                    }
                }
                // 对 j 进行去重操作
                ++j;
                while(j < n && nums[j] == nums[j - 1])  j++;
            }
            // 对 i 进行去重操作
            ++i;
            while(i < n && nums[i] == nums[i - 1])  i++;
        }
        return ret;
    }
};
// @lc code=end

