#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int jewelleryValue(vector<vector<int>> &frame)
    {
        int m = frame.size(), n = frame[0].size();
        // 创建 dp 表 + 初始化
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 填表
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};

int main()
{
    vector<vector<int>> grade;
    grade.push_back({1, 3, 1}, {1, 5, 1}, {4, 2, 1});
    Solution s;
    int ret = s.jewelleryValue(grade);
    cout << ret << endl;
    return 0;
}