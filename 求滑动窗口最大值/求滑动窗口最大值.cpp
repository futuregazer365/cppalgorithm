// leetcode239
// 求滑动窗口最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 单调队列

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int count = k;
        int i = 0;
        while (count--)
        {
            push(nums[i]);
            i++;
        }
        result.push_back(getMaxVal());
        for (int i = k; i < nums.size(); i++)
        {
            pop(nums[i - k]);
            push(nums[i]);
            result.push_back(getMaxVal());
        }
        return result;
    }
    void pop(int value) 
    {
        if (!que.empty()&&value==que.front()) 
        {
            que.pop_front();
        }
    }
    void push(int value) 
    {
        while (!que.empty() && value > que.back()) 
        {
            que.pop_back();
        }
        que.push_back(value);
    }
    int getMaxVal() 
    {
        return que.front();
    }
private:
    deque<int> que;
};
int main()
{
    Solution S;
    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    vector<int> result;
    S.push(nums[0]);
    S.push(nums[1]);
    S.push(nums[2]);
    result.push_back(S.getMaxVal());
    for (int i = 3; i < nums.size(); i++)
    {    
        S.pop(nums[i - 3]);
        S.push(nums[i]);
        result.push_back(S.getMaxVal());
    }
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
