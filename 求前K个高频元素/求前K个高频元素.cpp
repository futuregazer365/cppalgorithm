// 求前K个高频元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 347

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
    // 小顶堆
    /*
    大家对这个比较运算在建堆时是如何应用的，为什么左大于右就会建立小顶堆，反而建立大顶堆比较困惑。
    确实 例如我们在写快排的cmp函数的时候，return left>right 就是从大到小，return left<right 就是从小到大。
    优先级队列的定义正好反过来了，可能和优先级队列的源码实现有关（我没有仔细研究），
    我估计是底层实现上优先队列队首指向后面，队尾指向最前面的缘故！
    */
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    static bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
    bool(*compare)(const pair<int, int>& lhs, const pair<int, int>& rhs) = &cmp;
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        frequent(nums);
        for (auto &ky : frequence) 
        {
            pri_que.push(ky);
            if (pri_que.size() > k) 
            {
                pri_que.pop();
            }
        }
        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }

    void frequent(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); i++) 
        {
            frequence[nums[i]]++;//map的value默认为0
        }
    };
private:
    unordered_map<int, int> frequence;
    // 定义一个小顶堆，大小为k
    //参数1：pair<int, int>这是队列中每个元素的类型。在这里，每个元素都是一个存储两个整数的 pair，第一个整数是元素本身，第二个整数是元素的频率。
    //参数2：vector<pair<int, int>> 这是用于存储元素的底层容器类型。在这里，我们选择使用 vector 来存储 pair 类型的元素。
    //参数3：这是一个自定义的比较函数类，用于定义元素的比较规则。
    priority_queue < pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
};
int main()
{
    vector<int> v = { 2,1,2,1,1,3 };
    Solution S;
    vector<int> result = S.topKFrequent(v, 2);
    priority_queue<int, vector<int>, less<int>>s;//less表示按照递减(从大到小)的顺序插入元素
    priority_queue<int, vector<int>, greater<int>>s;//greater表示按照递增（从小到大）的顺序插入元素
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
