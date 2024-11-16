/*
 * @lc app=leetcode.cn id=1472 lang=cpp
 *
 * [1472] 设计浏览器历史记录
 */

// @lc code=start
#include <iostream>
#include <deque>
#include <string>
using namespace std;

class BrowserHistory
{
    deque<string> d;
    // 下标
    int index;

public:
    BrowserHistory(string homepage)
    {
        d = {homepage};
        index = 0;
    }

    void visit(string url)
    {
        // 删除后面的页面
        d.resize(index + 1);
        // 将要访问的 url 添加
        d.push_back(url);
        // 访问 url
        index = d.size() - 1;
    }

    string back(int steps)
    {
        // 浏览历史后退 steps 步
        index -= steps;
        if (index < 0)
            index = 0;
        return d[index];
    }

    string forward(int steps)
    {
        // 浏览历史前进 steps 步
        index += steps;
        if (index >= d.size())
            index = d.size() - 1;
        return d[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end
