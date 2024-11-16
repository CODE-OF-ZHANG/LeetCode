/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 *
 * [1486] 数组异或操作
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        // 创建 nums 数组
        vector<int> nums(n);
        // 初始化 nums 数组
        for(int i = 0; i < nums.size(); i++)
        {
            nums[i] = start + 2 * i;
        }
        int ret = 0;
        // 按位异或操作
        for (int i = 0; i < nums.size(); i++)
        {
            ret ^= nums[i];
        }
        return ret;
    }
};
// @lc code=end

