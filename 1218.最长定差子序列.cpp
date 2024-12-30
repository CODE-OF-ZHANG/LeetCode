/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        // 创建哈希表
        unordered_map<int, int> hash;
        // 初始化
        hash[arr[0]] = 1;
        // 填表 + 更新结果
        int ret = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            hash[arr[i]] = hash[arr[i] - difference] + 1;
            // 更新结果
            ret = max(ret, hash[arr[i]]);
        }
        // 返回结果
        return ret;
    }
};
// @lc code=end
