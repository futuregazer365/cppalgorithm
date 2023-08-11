// 二叉树的最小深度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode111
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
/*二叉树的定义*/
template<typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode() :val(), left(), right() {};
    TreeNode(T _val) :val(_val), left(), right() {};
    TreeNode(T _val, TreeNode<T>* _left, TreeNode<T>* _right) :val(_val), left(_left), right(_right) {};
};

/*前序数组构造二叉树 中——左——右*/
template<typename T>
TreeNode<T>* bulidTreeFromPreorder(const std::vector<T>& preorder, int& index)
{
    if (index >= preorder.size() || preorder[index] == T('\0'))
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
/*前序数组构造二叉树 中——左——右*/
template<typename T>
TreeNode<T>* bulidTreeFromPreorder(const std::vector<T>& preorder)
{
    int index = 0;
    return bulidTreeFromPreorder(preorder, index);
}
template<typename T>
class Solution {
public:
    int minDepth(TreeNode<T>* root) {
        return getHeight(root);
    }
    int getHeight(TreeNode<T>* node) 
    {
        if (node == nullptr) return 0;
        int leftDepth = getHeight(node->left);
        int rightDepth = getHeight(node->right);
        // 当一个左子树为空，右不为空，这时并不是最低点
        if (node->left == NULL && node->right != NULL) {
            return 1 + rightDepth;
        }
        // 当一个右子树为空，左不为空，这时并不是最低点
        if (node->left != NULL && node->right == NULL) {
            return 1 + leftDepth;
        }
        return min(leftDepth, rightDepth) + 1;
    }
};
int main()
{
    std::vector<char> preorder = { '2', '\0','3','\0','4','\0','5','\0','6'};
    TreeNode<char>* root = bulidTreeFromPreorder(preorder);
    Solution<char> S;
    int minDepth = S.minDepth(root);
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
