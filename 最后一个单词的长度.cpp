#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i = s.size() - 1;
        int sum = 0;
        // 去除末尾空格
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }
        while (i >= 0 && s[i] != ' ')
        {
            sum++;
            i--;
        }
        return sum;
    }
};

int main()
{
    string s = "Hello World";
    Solution so;
    int ret = so.lengthOfLastWord(s);
    cout << ret << endl;
    return 0;
}
