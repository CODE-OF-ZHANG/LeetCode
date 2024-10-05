/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int hash1[26] = { 0 };  // 统计字符串 p 中字符出现的次数
        for(auto ch : p)  hash1[ch - 'a']++;
        int hash2[26] = { 0 };  // 统计窗口里面每个字符出现的个数
        for(int left = 0, right = 0, count = 0; right < s.size(); right++) {
            char in = s[right];
            if(++hash2[in - 'a'] <= hash1[in - 'a'])  count++;  // 进窗口 + 维护 count
            if(right - left + 1 > p.size())  // 判断
            {
                char out = s[left++];
                if(hash2[out - 'a']-- <= hash1[out - 'a'])  count--;  // 出窗口 + 维护 count
            }
            // 更新结果
            if(count == p.size())  ret.push_back(left);
        }
        return ret;
    }
};
// @lc code=end

