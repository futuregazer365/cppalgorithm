// 无重叠区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 435

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& interval1, vector<int>& interval2) {
            if (interval1[0] < interval2[0])return true;
            else return false;
            });
        int result = 0;
        for (int i = 1; i < intervals.size(); i++) 
        {
            if (intervals[i][0] < intervals[i - 1][1]) //两个区间相交
            {
                intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
                result++;
            }
            else {
                
            }
        }
        return result;
    }
};
int main()
{   
    vector<vector<int>> intervals = { {1,2},{3,6},{7,12},{4,5},{10,16} };
    Solution S;
    int result = S.eraseOverlapIntervals(intervals);
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
