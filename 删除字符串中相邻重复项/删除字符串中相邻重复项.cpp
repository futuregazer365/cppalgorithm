// 删除字符串中相邻重复项.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 利用栈（此程序使用字符串模拟串）

#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    string eraseCharacters(string S) 
    {
        string result;
        for (auto s : S) 
        {
            if (result.empty() || s != result.back()) 
            {
                result.push_back(s);
            }
            else 
            {
                result.pop_back();
            }
        }
        return result;
    }

private:
    stack<char> st;
};

int main()
{
    string S = "abbghdgrvfffsfaca";
    Solution t;
    cout<<t.eraseCharacters(S)<<endl;
    return 0;
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
