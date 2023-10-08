// 分割等和子集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num: nums) 
        {
            sum += num;
        }
        if (sum % 2 != 0) 
        {
            return false;
        }
        int target = sum / 2;
        vector<int>dp(target + 1);
        for (auto num : dp) 
        {
            num = 0;
        }
        for (int i = 0; i < nums.size(); i++) //遍历物品
        {
            for (int j = target; j >= nums[i]; j--) 
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (target == dp[target]) 
        {
            return true;
        }
        else {
            return false;
        }
    }
};
int main()
{
    Solution S;
    vector<int> nums{ 1,2,3,5 };
    bool result = S.canPartition(nums);
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
