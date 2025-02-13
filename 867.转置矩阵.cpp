/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ret(n, vector<int>(m));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ret[j][i] = matrix[i][j];
            }
        }
        return ret;
    }
};
// @lc code=end
