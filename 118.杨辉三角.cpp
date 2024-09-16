/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vv;
        vv.resize(numRows);
        for (int i = 0; i < numRows; i++)
        {
            vv[i].resize(i + 1);
        }
        for (int i = 0; i < numRows; i++)
        {
            vv[i][0] = vv[i][i] = 1;
        }
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (vv[i][j] == 0)
                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
            }
        }
        return vv;
    }
};
// @lc code=end
