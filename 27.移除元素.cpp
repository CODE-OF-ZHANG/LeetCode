/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    if(nums.size() == 0)
        return 0;
    int i = 0;
    for (int j = 0; j < nums.size(); j++){
        if (nums[j] == val);
        else
        {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
    }
};

// @lc code=end

