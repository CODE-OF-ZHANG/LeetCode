/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        // 1. 处理边界情况
        if (numRows == 1)
            return s;
        // 2. 处理第一行
        string ret;
        int n = s.size(), d = 2 * numRows - 2;
        for (int i = 0; i < n; i += d)
            ret += s[i];
        // 3. 处理中间行
        for (int k = 1; k < numRows - 1; k++)
        {
            for (int i = k, j = d - k; i < n || j < n; i += d, j += d)
            {
                if (i < n)
                    ret += s[i];
                if (j < n)
                    ret += s[j];
            }
        }
        // 4. 处理最后一行
        for (int i = numRows - 1; i < n; i += d)
        {
            ret += s[i];
        }
        return ret;
    }
};
// @lc code=end
