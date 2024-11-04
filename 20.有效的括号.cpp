/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    char pair(char a)
    {
        if (a == ')')
            return '(';
        if (a == ']')
            return '[';
        if (a == '}')
            return '{';
        return 0;
    }

    bool isValid(string s)
    {
        int n = s.size();
        // 如果字符串个数为奇数, 则说明必有一个括号不能顺利闭合
        if (n % 2 == 1)
            return false;
        int stk[n + 1], top = 0;
        for (int i = 0; i < n; i++)
        {
            // 如果s[i]是左括号,就会入栈,如果是右括号,就看是否有匹配的
            char ch = pair(s[i]);
            if (ch)
            {
                if (top == 0 || stk[top - 1] != ch)
                    return false;
                top--; // 出栈后元素减一
            }
            else
                stk[top++] = s[i]; // 入栈
        }
        return top == 0; // 栈空说明全部匹配成功
    }
};

// @lc code=end

