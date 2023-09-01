// 递增的子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(0, nums);
        return result;
    }
    void backtracking(int startindex, vector<int>& nums) {
        if (path.size() >= 2) {
            result.push_back(path);
        }
        if (startindex >= nums.size()) { return; }
        unordered_set<int> mset;
        for (int i = startindex; i < nums.size(); i++) {
            bool b1 = !path.empty();
            bool b2 = mset.find(nums[i]) != mset.end();
            bool b3 = false;
            if(b1)b3 = nums[i] >= path.back();
            if ((!path.empty() && nums[i] < path.back())||(mset.find(nums[i]) != mset.end())) {//去重+判断是否合法<+____TMD注意了为什么谢了这么多日志代码？？？就是因为b3条件写反了！！！！！！！！！！！！！！
                continue;
            }
            mset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(i + 1, nums);
            path.pop_back();
        }
    }
private:
    vector<int> path;
    vector<vector<int>> result;
};
int main()
{
    vector<int> vec = { 4,4,3,2,1 };
    Solution S;
    vector<vector<int>> result = S.findSubsequences(vec);
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
