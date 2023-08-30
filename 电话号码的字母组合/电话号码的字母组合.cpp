// 电话号码的字母组合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 17
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        backtracking(digits, 0);
        return result;
    }
    void backtracking(const string&digits,int index) {
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }
        int digit = digits[index] - '0';        // 将index指向的数字转为int
        string letters = letterMap[digit];
        for (int i = 0; i < letters.size(); i++) 
        {
            path.push_back(letters[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }
private:
    string path;
    vector<string> result;
    vector<string> letterMap = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
};

class Solution2 {
public:
    vector<string> letterCombinations(string digits) {
        backtracking(digits.size(), digits, 0);
        return result;
    }
    void backtracking(int k, const string& digits, int index) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        int digit = digits[index] - '0';  // 将index指向的数字转为int
        string letter = letterMap[digit];
        for (int i = 0; i < letter.size(); i++) {
            path.push_back(letter[i]);
            backtracking(k, digits, index + 1);//警告：在递归中非必要不要使用自增或自减
            path.pop_back();
        }

    }
private:
    string path;
    vector<string> result;
    vector<string> letterMap = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
};
int main()
{
    Solution2 S;
    vector<string> result = S.letterCombinations("34");
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
