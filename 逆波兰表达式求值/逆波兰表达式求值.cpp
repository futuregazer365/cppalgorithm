// 逆波兰表达式求值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 本文的主角叫 逆波兰表达式，也叫后缀表达式。后者这个比较通俗的名字很明确的表示了自己的含义，意思是计算的符号在要计算的两个数字之后。
// 我们常用的算术表达式是中缀表达式，计算符号在两个数字之间。在现实中基本没有直接给出一个逆波兰表达式的场景，
// 也就意味着必须先将中缀表达式转换成逆波兰表达式。
// 1 + ( 2 - 3 * 4 ) / 5 + 6》》》》》中缀表达式
// 1 2 3 4 * - 5 / 6 + 》》》》》后缀表达式

//基本思想，遇到数字加入到栈，遇到操作符从栈里取元素
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <string>
using namespace std;
class Solution
{
public:
    string calculate(vector<string>& tokens)
    {
        for (size_t i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*")
            {
                
                int a = atoi(st.top().c_str()); st.pop();
                int b = stoi(st.top()); st.pop();
                if (tokens[i] == "+")
                {
                    st.push(to_string(a + b));
                }
                else if(tokens[i] == "-")
                {
                    st.push(to_string(b - a));
                }
                else if (tokens[i] == "/")
                {
                    st.push(to_string(b / a));
                }
                else if (tokens[i] == "*")
                {
                    st.push(to_string(a * b));
                }
            }
            else 
            {
                st.push(tokens[i]);
            }
        }
        return st.top();
    }

private:
    stack<string> st;
};


int main()
{
    vector<string> tokens = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };//((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    Solution S;
    cout << S.calculate(tokens) << endl;

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
