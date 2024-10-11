/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int hash1[128] = { 0 };  // 统计字符串t中字符出现的频次
        int kinds = 0;  // 统计有效字符的种类
        for(auto ch : t)
            if(hash1[ch]++ == 0)  kinds++;
        int hash2[128] = { 0 };  // 统计窗口内每个字符出现的频次
        int minlen = INT_MAX, begin = -1;
        for(int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];
            if(++hash2[in] == hash1[in])  count++;  // 进窗口 + 维护count
            while(count == kinds)  // 判断条件
            {
                if(right - left + 1 < minlen)  // 更新结果
                {
                    minlen = right - left + 1;
                    begin = left;
                }
                char out = s[left++];
                if(hash2[out]-- == hash1[out])  count--;  // 出窗口 + 维护count
            }
        }
        if(begin == -1)  return "";
        else return s.substr(begin, minlen);
    }
};
// @lc code=end

