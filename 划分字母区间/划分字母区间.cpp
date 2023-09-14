// 划分字母区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode763

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> hash(26);
        vector<int> result;
        for (int i = 0; i < s.size(); i++) //记录每个字母最后出现的位置
        {
            hash[s[i] - 'a'] = i;
        }
        int bound = hash[s[0] - 'a'];
        for (int i = 1; i < s.size(); i++) 
        {
            if (hash[s[i] - 'a'] > bound)
            {
                bound = hash[s[i] - 'a'];
            }
            if (bound == i) {
                result.push_back(bound);
            }
            
        }
        vector<int> rresult1;
        for (int i = 0; i < result.size(); i++)
        {
            if (i == 0) { rresult1.push_back(result[i] + 1); }
            else {
                rresult1.push_back(result[i] - result[i - 1]);
            }
        }
        return rresult1;
    }
};
int main()
{
    Solution S;
    vector<int> result = S.partitionLabels("ababcbacadefegde");
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
