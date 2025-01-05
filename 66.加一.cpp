/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        // 取数组的每一位, 不需要进位的情况
        for (int i = n - 1; i >= 0; i--)
        {
            // 数组的最后一位数加一
            digits[i]++;
            // 加一后模10
            digits[i] = digits[i] % 10;
            // 如果数组的当前位数不是0的话, 说明没有进位, 直接返回即可
            if(digits[i] != 0)
                return digits;
        }
        // 需要进位
        vector<int> ans(n + 1);
        ans[0] = 1;
        return ans;
    }
};
// @lc code=end

