/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// // 高斯求和
// class Solution
// {
// public:
//     int missingNumber(vector<int> &nums)
//     {
//         int n = nums.size();
//         // 0 到 n 的数的和
//         int total = n * (n + 1) / 2;
//         // 数组里面所有元素的和
//         int arrSum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             arrSum += nums[i];
//         }
//         return total - arrSum;
//     }
// };

// // 哈希集合
// class Solution
// {
// public:
//     int missingNumber(vector<int> &nums)
//     {
//         unordered_set<int> hash;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             hash.insert(nums[i]);
//         }
//         int ret = -1;
//         for (int i = 0; i <= nums.size(); i++)
//         {
//             if(!hash.count(i))
//             {
//                 ret = i;
//                 break;
//             }
//         }
//         return ret;
//     }
// };

// 位运算
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ret = 0;
        // 按位异或数组里的值
        for (const auto &e : nums)
        {
            ret ^= e;
        }
        // 按位异或 0 ~ n 之间所有的数
        for (int i = 0; i <= nums.size(); i++)
        {
            ret ^= i;
        }
        return ret;
    }
};
// @lc code=end
