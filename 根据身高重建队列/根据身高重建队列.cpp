// 根据身高重建队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 406

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> result(people.size());
        for (int i = 0; i < people.size(); i++) 
        {
            if (i == 0) { result[0] = people[0]; continue; };
            if (people[i][1] < i) //前面人太多了
            {
                result.insert(result.begin() + people[i][1], people[i]);
            }
            else 
            {
                result.insert(result.begin() + i, people[i]);
            }
            
        }
        result.resize(people.size());
        return result;
    }
    static bool compare(vector<int>& p1, vector<int>& p2) 
    {
        if (p1[0] > p2[0])return true;
        if (p1[0] == p2[0]) 
        {
            if (p1[1] < p2[1])return true;
            else
            {
                return false;
            }
        }
        if (p1[0] < p2[0])return false;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> people{ {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
    vector<vector<int>> result = S.reconstructQueue(people);
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
