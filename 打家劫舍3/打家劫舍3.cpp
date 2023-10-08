// 打家劫舍3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 337

#include <iostream>
#include <vector>
using namespace std;
/*二叉树的定义*/
template<typename T>
class TreeNode
{
public:
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :left(nullptr), right(nullptr) {};
    TreeNode(T _val) :val(_val), left(nullptr), right(nullptr) {};
    TreeNode(T _val, TreeNode* _left, TreeNode* _right) :val(_val), left(_left), right(_right) {};

};

template<typename T>
TreeNode<T>* bulidTreeFromPreorder(const std::vector<T>& preorder, int& index)
{
    if (index >= preorder.size() || preorder[index] == T(0))
    {
        index++;
        return nullptr;
    }
    TreeNode<T>* node = new TreeNode<T>(preorder[index]);
    index++;
    node->left = bulidTreeFromPreorder(preorder, index);
    node->right = bulidTreeFromPreorder(preorder, index);
    return node;
}
/*前序数组构造二叉树*/
template<typename T>
TreeNode<T>* buildTreeFromPreorder(const std::vector<T>& preorder)
{
    int index = 0;
    return bulidTreeFromPreorder(preorder, index);
}

class Solution {
public:
    int rob(TreeNode<int>* root) {
        if (!root)return 0;
        vector<int>dp = traversal(root);
        return max(dp[0], dp[1]);
    }
    //dp[0]与dp[1]是该节点下，是否偷这个节点所得到的物品价值
    //由于是递归，所以每个节点的值都存在了递归栈里
    vector<int> traversal(TreeNode<int>* root) 
    {
        if (root == nullptr)return vector<int>{0, 0};
        vector<int> leftdp = traversal(root->left);
        vector<int> rightdp = traversal(root->right);
        int bounds = root->val + leftdp[0] + rightdp[0];//root节点我偷
        int bounds2 = max(leftdp[0], leftdp[1]) + max(rightdp[0], rightdp[1]);//root节点不偷
        return vector<int>{bounds2, bounds};
    }
};
int main()
{
    
    std::vector<int> preorder = {3,2,0,3,0,0,3,0,1,0,0};
    TreeNode<int> *root = buildTreeFromPreorder(preorder);
    Solution S;
    int result = S.rob(root);
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
