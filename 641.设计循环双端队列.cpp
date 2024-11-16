/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
#include<iostream>
#include<deque>
using namespace std;

class MyCircularDeque
{
public:
    deque<int> d;
    int capacity;
    int size;
    // 构造函数
    MyCircularDeque(int k)
    {
        d.clear();
        capacity = k;
        size = 0;
    }

    bool insertFront(int value)
    {
        // 满了的情况
        if (size == capacity)
            return false;
        // 头插
        size++;
        d.push_front(value);
        return true;
    }

    bool insertLast(int value)
    {
        // 满了的情况
        if (size == capacity)
            return false;
        // 尾插
        size++;
        d.push_back(value);
        return true;
    }

    bool deleteFront()
    {
        // 为空
        if (size == 0)
            return false;
        // 头删
        size--;
        d.pop_front();
        return true;
    }

    bool deleteLast()
    {
        // 为空的情况
        if (size == 0)
            return false;
        // 尾删
        size--;
        d.pop_back();
        return true;
    }

    int getFront()
    {
        // 为空的情况
        if (size == 0)
            return -1;
        return d.front();
    }

    int getRear()
    {
        // 为空的情况
        if (size == 0)
            return -1;
        return d.back();
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end
