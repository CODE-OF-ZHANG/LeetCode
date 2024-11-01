#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int massage(vector<int> &nums)
    {
        // 1. 创建 dp 表 + 处理边界情况
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<int> f(n);
        auto g = f;
        // 2. 初始化
        f[0] = nums[0];
        // 3. 填表
        for (int i = 1; i < n; i++)
        {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(g[i - 1], f[i - 1]);
        }
        // 4. 返回值
        return max(f[n - 1], g[n - 1]);
    }
};


int main()
{
    vector<int> nums;
    // [2, 1, 4, 5, 3, 1, 1, 3]
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(3);
    Solution s;
    int ret = s.massage(nums);
    cout << ret << endl;
    return 0;
}