/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include<ctime>
#include <vector>
using namespace std;

// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        // 随机数种子
        srand(time(NULL));
        // 排序函数
        qsort(nums, 0, nums.size() - 1);

        return nums;
    }

    // 快排
    void qsort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return;
        // 选取基准值
        int key = getrandom(nums, l, r);
        // 数组分三块
        int left = l - 1, right = r + 1;
        for (int i = l; i < right;)
        {
            if (nums[i] < key)
                swap(nums[++left], nums[i++]);
            else if (nums[i] == key)
                i++;
            else
                swap(nums[--right], nums[i]);
        }
        // 递归实现  --> [l, left] [left + 1, right - 1] [right, r]
        qsort(nums, l, left);
        qsort(nums, right, r);
    }

    // 获取随机数
    int getrandom(vector<int> &nums, int left, int right)
    {
        int r = rand();
        return nums[r % (right - left + 1) + left];
    }
};
// @lc code=end
