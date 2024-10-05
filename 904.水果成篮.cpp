/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& f) {
        int hash[100001] = { 0 };
        int ret = 0;
        for(int left = 0, right = 0, kinds = 0; right < f.size(); right++) {
            if(hash[f[right]] == 0)  kinds++;
            hash[f[right]]++;  // 进窗口
            while(kinds > 2) {  // 判断
                hash[f[left]]--;   // 出窗口
                if(hash[f[left]] == 0)  kinds--;
                left++;
            }
            ret = max(ret, right - left + 1);  // 更新结果
        }
        return ret;
    }
};
// @lc code=end

