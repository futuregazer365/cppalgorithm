// 用最小数量的剑引爆气球.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 452
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#include <iostream>
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0)return 0;
        int result = 1;
        sort(points.begin(), points.end(), [](vector<int>& p1, vector<int>& p2)
            {
                if (p1[0] > p2[0])return false;
                else {
                    return true;
                }
            });
        for (int i = 1; i < points.size(); i++) 
        {
            if (points[i][0] > points[i - 1][1]) //此气球和上一个气球不沾边
            {
                result++;
            }
            else {
                //此气球和上一个气球沾边,我们判断这两个气球所占位置的交集，将i气球的右边界更新，进行下一次比较
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
        }
        return  result;
    }
    static bool compare(vector<int>& p1, vector<int>& p2)
    {
        if (p1[0] > p2[0])return false;
        else {
            return true;
        }

    }
};
int main()
{
    vector<vector<int>> points{ {1,2},{3,6},{7,12},{4,8},{10,16}};
    Solution S;
    int result = S.findMinArrowShots(points);
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
