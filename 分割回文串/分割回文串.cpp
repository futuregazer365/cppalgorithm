// 分割回文串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 131
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    /*
    检测子串是否是回文字串
    */
    bool ispalindrome(const string s, int startindex, int i)
    {
        bool sw = true;
        while (startindex <= i) {
            if (s[startindex] != s[i]) { sw = false; break; }
            startindex++;
            i--;
        }
        return sw;
    }
    vector<vector<string>> partition(string s) {
        path.clear();
        result.clear();
        backtracking(s, 0);
        return result;
    }
    void backtracking(const string &s,int startindex) 
    {
        if (startindex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startindex; i < s.size(); i++) {
            if (ispalindrome(s, startindex, i)) {//是回文字串
                string str = s.substr(startindex, i - startindex + 1);
                path.push_back(str);
                backtracking(s, i + 1);
                path.pop_back();
            }
            else {
                continue;
            }
        }
    }
private:
    vector<string> path;
    vector<vector<string>> result;
};
int main()
{
    Solution S;
    string s = "aab";
    vector<vector<string>> result = S.partition(s);
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
