/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         vector<int> cnt(26, 0);
//         if(t.size() > s.size())  return false;
//         for(const auto& ch : t)
//         {
//             cnt[ch - 'a']++;
//         }
//         for(const auto& ch : s)
//         {
//             cnt[ch - 'a']--;
//             if(cnt[ch - 'a'] < 0)
//                 return false;
//         }
//         return true;
//     }
// };

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int m = s.size(), n = t.size();
        if (m != n)
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
// @lc code=end
