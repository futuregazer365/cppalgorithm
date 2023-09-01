// 复原IP地址.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 93
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    /*
    判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
    */
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) { // 0开头的数字不合法
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(0, s, 0);
        return result;
    }
    void backtracking(int startindex, string& s,int pointCount) {
        if (pointCount == 3) {
            if (isValid(s, startindex, s.size() - 1)) {//第三个点后面的ip段是正确的，也就是说4段Ip全部真确
                result.push_back(s);
                return;
            }
            return;
        }
        for (int i = startindex; i < s.size(); i++) {
            if (isValid(s, startindex, i)) {
                s.insert(s.begin() + i + 1, '.');
                pointCount += 1;
                backtracking(i + 2, s, pointCount);
                s.erase(s.begin() + i + 1);
                pointCount -= 1;
            }
        }
    }
private:
    vector<string> result;
};
int main()
{
    Solution S;
    string str = "";
    vector<string> result = S.restoreIpAddresses(str);
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
