// 合并区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0)return result;
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) {
            if (v1[0] < v2[0])return true;
            else
            {
                return false;
            }
            });
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) 
        {
            if (intervals[i][0] <= result.back()[1]) 
            {//开始合并
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            }
            else {//不进行合并
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
int main()
{
    vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18},{12,16} };
    Solution S;
    S.merge(intervals);
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
