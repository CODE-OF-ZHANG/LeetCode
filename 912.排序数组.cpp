/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <ctime>
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

// 快速选择排序
// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         // 随机数种子
//         srand(time(NULL));
//         // 排序函数
//         qsort(nums, 0, nums.size() - 1);

//         return nums;
//     }

//     // 快排
//     void qsort(vector<int> &nums, int l, int r)
//     {
//         if (l >= r)
//             return;
//         // 选取基准值
//         int key = getrandom(nums, l, r);
//         // 数组分三块
//         int left = l - 1, right = r + 1;
//         for (int i = l; i < right;)
//         {
//             if (nums[i] < key)
//                 swap(nums[++left], nums[i++]);
//             else if (nums[i] == key)
//                 i++;
//             else
//                 swap(nums[--right], nums[i]);
//         }
//         // 递归实现  --> [l, left] [left + 1, right - 1] [right, r]
//         qsort(nums, l, left);
//         qsort(nums, right, r);
//     }

//     // 获取随机数
//     int getrandom(vector<int> &nums, int left, int right)
//     {
//         int r = rand();
//         return nums[r % (right - left + 1) + left];
//     }
// };

// 归并排序 --> 递归里面开空间
// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         mergesort(nums, 0, nums.size() - 1);
//         return nums;
//     }

//     // 归并排序
//     void mergesort(vector<int> &nums, int left, int right)
//     {
//         // 处理边界情况
//         if (left >= right)
//             return;

//         // 找出中间值, 划分数组
//         int mid = (left + right) >> 1;
//         mergesort(nums, left, mid);
//         mergesort(nums, mid + 1, right);
//         // 合并两个有序数组
//         vector<int> tmp(right - left + 1);
//         int cur1 = left, cur2 = mid + 1, i = 0;
//         while (cur1 <= mid && cur2 <= right)
//             tmp[i++] = nums[cur1] <= nums[cur2] ? nums[cur1++] : nums[cur2++];
//         // 处理没有遍历完的数组
//         while (cur1 <= mid)
//             tmp[i++] = nums[cur1++];
//         while (cur2 <= right)
//             tmp[i++] = nums[cur2++];

//         // 还原
//         for (int i = left; i <= right; i++)
//         {
//             nums[i] = tmp[i - left];
//         }
//     }
// };

// 归并排序 --> 全局里面开空间
class Solution
{
public:
    vector<int> tmp;
    vector<int> sortArray(vector<int> &nums)
    {
        // 提前开空间
        tmp.resize(nums.size());
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }

    // 归并排序
    void mergesort(vector<int> &nums, int left, int right)
    {
        // 处理边界情况
        if (left >= right)
            return;

        // 找出中间值, 划分数组
        int mid = (left + right) >> 1;
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);
        // 合并两个有序数组
        int cur1 = left, cur2 = mid + 1, i = 0;
        while (cur1 <= mid && cur2 <= right)
            tmp[i++] = nums[cur1] <= nums[cur2] ? nums[cur1++] : nums[cur2++];
        // 处理没有遍历完的数组
        while (cur1 <= mid)
            tmp[i++] = nums[cur1++];
        while (cur2 <= right)
            tmp[i++] = nums[cur2++];

        // 还原
        for (int i = left; i <= right; i++)
        {
            nums[i] = tmp[i - left];
        }
    }
};
// @lc code=end
