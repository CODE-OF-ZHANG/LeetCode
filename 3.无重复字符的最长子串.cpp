/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, n = s.size(), ret = 0;
        int hash[128] = { 0 };
        while(right < n){
            hash[s[right]]++;  // 进入窗口
            while(hash[s[right]] > 1)  // 判断
                hash[s[left++]]--;
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};
// @lc code=end

