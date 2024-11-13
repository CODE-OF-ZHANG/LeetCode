/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        // 这个数的余数
        hash[0] = 1;
        int sum = 0, ret = 0;
        for (auto x : nums)
        {
            // 算出当前位置的前缀和
            sum += x;
            // 修正后的余数
            int r = (sum % k + k) % k;
            // 统计结果
            if (hash.count(r))
                ret += hash[r];
            hash[r]++;
        }
        return ret;
    }
};
// @lc code=end
