#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++)  cin >> arr[i];

    // 预处理出来一个前缀和数组
    vector<long long> dp(n + 1);  // 防止数据溢出
    for(int i = 1; i <= n; i++)  dp[i] = dp[i - 1] + arr[i];
    int r = 0, l = 0;
    while(q--)
    {
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] <<endl;
    }
    return 0;
}
