/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 1. 暴力解法
// class Solution
// {
// public:
//     int subarraySum(vector<int> &nums, int k)
//     {
//         // 1. 暴力解法
//         int n = nums.size(), count = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i; j < n; j++)
//             {
//                 int sum = 0;
//                 for (int left = i; left <= j; left++)
//                     sum += nums[left];
//                 if (sum == k)
//                     count++;
//             }
//         }
//         return count;
//     }
// };

// 2. 算法优化
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int sum = 0, ret = 0;
        for(auto e : nums)
        {
            sum += e;
            if(hash.count(sum - k))
                ret += hash[sum - k];
            hash[sum]++;
        }
        return ret;
    }
};
// @lc code=end
