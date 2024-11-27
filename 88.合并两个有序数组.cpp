/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, ret = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            // 比较nums1和nums2中的元素大小
            if (nums1[i] < nums2[j])
                nums1[ret--] = nums2[j--];
            else
                nums1[ret--] = nums1[i--];
        }
        // nums1中没有元素, i 就会小于0
        if (i < 0)
        {
            // 如果num2中有元素, 直接放到nums1中即可
            while (j >= 0)
                nums1[ret--] = nums2[j--];
        }
    }
};
// @lc code=end
