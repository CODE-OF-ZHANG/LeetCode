/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 1. 两个 set 进行去重
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        // 结果
        vector<int> v;

        auto it1 = s1.begin();
        auto it2 = s2.begin();
        // 比较  有一个结束就结束
        while(it1 != s1.end() && it2 != s2.end())
        {
            // 比较, 小的就++
            if(*it1 > *it2)
            {
                ++it2;
            }
            else if(*it1 < *it2)
            {
                ++it1;
            }
            else
            {
                // 相等的就是交集, 两个同时++
                v.push_back(*it1);
                ++it1;
                ++it2;
            }
        }
        return v;
    }
};
// @lc code=end

