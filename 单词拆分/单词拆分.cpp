// 单词拆分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 139 难

#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //dp[i]长度为i的字串是否可以被拆分
        vector<bool> dp(s.size() + 1, 0);
        dp[0] = true;
        set<string> wordSet;
        for (auto& word : wordDict) 
        {
            wordSet.insert(word);
        }
        for (int i = 0; i <= s.size(); i++) //背包
        {
            for (int j = 0; j < i; j++)//物品
            {
                string word = s.substr(j, i - j); //substr(起始位置，截取的个数)
                //长度为dp[i]的字符串是否可以拆分，表现为，dp[j](长度为i的字符串已验证可以拆分)+下标[j,i）在字典中可以查到
                //举个例子，j = 0时，表示[0,i]是否可以在字典中找到，找到了意味着可以拆分，找不到意味着不可以拆分 
                if (wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
int main()
{
    string s = "123456789";
    string word = s.substr(1, 2);
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
