/*
 * @lc app=leetcode.cn id=1419 lang=cpp
 *
 * [1419] 数青蛙
 */

// @lc code=start
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

class Solution
{
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        string s = "croak";
        int n = s.size();
        // 遍历字符串, 将字符添加到数组中
        vector<int> hash(n);
        unordered_map<char, int> index;
        for (int i = 0; i < n; i++)
        {
            index[s[i]] = i;
        }
        // 扫描字符串
        for (const auto &ch : croakOfFrogs)
        {
            if (ch == 'c')
            {
                if (hash[n - 1] != 0)
                    hash[n - 1]--;
                hash[0]++;
            }
            else
            {
                int i = index[ch];
                if (hash[i - 1] == 0)
                    return -1;
                hash[i - 1]--;
                hash[i]++;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (hash[i] != 0)
                return -1;
        }
        return hash[n - 1];
    }
};

// @lc code=end

