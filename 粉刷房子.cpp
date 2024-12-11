#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        // 创建 dp 表 + 初始化
        vector<vector<int>> dp(n + 1, vector<int>(3));
        // 填表 --> 从左往右填, 三个表同时填
        for (int i = 1; i <= n; i++)
        {
            // 注意: 创建的 dp 表是 n + 1 大小的, 所以 costs 要减一
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i - 1][2];
        }
        // 确认返回值
        return min(dp[n][0], min(dp[n][1], dp[n][2]));
    }
};

int main()
{
    vector<vector<int>> costs = {{17, 2, 17},
                                 {16, 16, 5},
                                 {14, 3, 19}};
    Solution s;
    int ret = s.minCost(costs);
    cout << ret << endl;
    return 0;
}