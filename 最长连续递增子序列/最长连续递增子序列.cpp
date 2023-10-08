// 最长连续递增子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// LeetCode：674
#include <vector> 
#include <iostream>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0)return 0;
        if (nums.size() == 1)return 1;
        //dp[i]尾部为nums[i]时最大的连续子数组长度是dp[i]
        vector<int> dp(nums.size(),1);
        //为什么初始化为1呢？
        //因为dp[i]表示以nums[i]为结尾的最长递增子序列长度，至少有nums[i]在里面占一个长度
        int result = 0;
        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[i] > nums[i - 1]) 
            {
                dp[i] = dp[i - 1] + 1;
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
int main()
{
    vector<int>nums{ 1,3,5,4,7 };
    Solution S;
    int result = S.findLengthOfLCIS(nums);
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
