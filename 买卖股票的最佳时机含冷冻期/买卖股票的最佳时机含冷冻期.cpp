#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //定义dp数组
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        //初始化dp数组
        dp[0][0] = -prices[0];//持有股票现在的金额
        dp[0][1] = 0;//保持卖出的状态所拥有的金额
        dp[0][2] = 0;//卖出所拥有的金额
        dp[0][3] = 0;//冷冻期所拥有的金额
        for (int i = 1; i < prices.size(); i++) 
        {
            dp[i][0] = maxin3nums(dp[i - 1][0], dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return maxin3nums(dp[prices.size() - 1][1], dp[prices.size() - 1][2], dp[prices.size() - 1][3]);
    }
    int maxProfit2(vector<int>& prices) 
    {
        //定义dp数组
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        //初始化dp数组
        dp[0][0] = 0;//不做任何措施
        dp[0][1] = -prices[0];//持有股票现在的金额
        dp[0][2] = 0;//保持卖出的状态所拥有的金额
        dp[0][3] = 0;//卖出所拥有的金额
        dp[0][4] = 0;//冷冻期所拥有的金额
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(maxin3nums(dp[i - 1][1], dp[i - 1][0] - prices[i], dp[i - 1][2] - prices[i]), dp[i - 1][4] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][4]);
            dp[i][3] = dp[i - 1][1] + prices[i];
            dp[i][4] = dp[i - 1][3];
        }
        return maxin3nums(dp[prices.size() - 1][2], dp[prices.size() - 1][3], dp[prices.size() - 1][4]);
    }
    int maxin3nums(int a, int b, int c)const 
    {
        int d;
        d = a > b ? a : b;
        d = d > c ? d : c;
        return d;
    }
};
int main() 
{

    vector<int>price{ 1,2,3,0,2 };
    Solution S;
    int result = S.maxProfit(price);
    int result2 = S.maxProfit2(price);
    std::cout << "Hello World!\n";
}