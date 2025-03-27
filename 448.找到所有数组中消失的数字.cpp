/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        set<int> st;
        vector<int> ans;
        // 将1 ~ n中所有的数插入到set中
        for (int i = 1; i <= nums.size(); i++)
        {
            st.insert(nums[i - 1]);
        }
        // 判断nums数组中哪个数不在1 ~ n中, 插入到ans
        for (int i = 1; i <= nums.size(); i++)
        {
            if (!st.count(i))
                ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end
