/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        // 将数字转换成字符串
        vector<string> strs;
        for (const auto &x : nums)
            strs.push_back(to_string(x));
        // 排序
        sort(strs.begin(), strs.end(), [](const string &s1, const string &s2)
             { return s1 + s2 > s2 + s1; });
        // 提取结果
        string ret;
        for (const auto &s : strs)
            ret += s;
        // 判断特殊情况
        if (ret[0] == '0')
            return "0";
        return ret;
    }
};
// @lc code=end
