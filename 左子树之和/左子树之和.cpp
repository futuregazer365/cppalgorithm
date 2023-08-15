// 左子树之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
template<typename T>
class Solution {
public:
    int sumOfLeftLeaves(TreeNode<T>* root) {
        return laterordertraversal(root);
    }
    int laterordertraversal(TreeNode<T>* node) 
    {
        if (node == nullptr)return 0;
        int left = laterordertraversal(node->left);
        if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr) 
        {
            left += node->left->val;
        }
        int right = laterordertraversal(node->right);
        return left + right;
        
    }
};
int main()
{
    std::vector<int> preorder = { 1,4,8,0,0,3,0,0,5,6,0,0,12 };
    TreeNode<int>* root = buildTreeFromPreorder(preorder);
    Solution<int> s;
    int result = s.sumOfLeftLeaves(root);
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
