// 用栈实现队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stack>
#include <iostream>
using namespace std;
class Solution
{
public:

    //入队
    void push(int x) 
    {
        instack.push(x);
    };
    int pop() 
    {
        if (outstack.empty()) {
            while (!instack.empty())
            {
               int i = instack.top();
               instack.pop();
               outstack.push(i);
            }
        }
        if (!outstack.empty())
        {
            int result = outstack.top();
            outstack.pop();
            return result;
        }

    };
private:
    stack<int> instack;
    stack<int> outstack;
};
int main()
{
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.pop() << endl;
    s.push(5);
    cout << s.pop() << endl;
    s.push(6);
    s.push(7);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
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
