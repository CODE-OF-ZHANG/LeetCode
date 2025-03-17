/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        // 排序
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int m = nums1.size(), n = nums2.size(), idx1 = 0, idx2 = 0;
        vector<int> ret;
        while (idx1 < m && idx2 < n)
        {
            if (nums1[idx1] < nums2[idx2])
                idx1++;
            else if (nums1[idx1] > nums2[idx2])
                idx2++;
            else
            {
                ret.push_back(nums1[idx1]);
                idx1++;
                idx2++;
            }
        }
        return ret;
    }
};
// @lc code=end
