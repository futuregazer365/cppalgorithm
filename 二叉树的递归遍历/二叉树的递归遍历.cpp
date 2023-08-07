// 二叉树的递归遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
TreeNode<T>* bulidTreeFromPreorder(const std::vector<T>& preorder,int &index)
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
/*前序数组构造二叉树*/
template<typename T>
TreeNode<T>* buildTreeFromPreorder(const std::vector<T>& preorder)
{
    int index = 0;
    return bulidTreeFromPreorder(preorder, index);
}


class Solution
{

public:
    template<typename T>
    vector<T>preorderTraversal(TreeNode<T>* root) 
    {
        vector<T> result;
        preorderTraversal1(root, result);
        return result;
    };
    template<typename T>
    void preorderTraversal1(TreeNode<T>* cur,vector<T> &result)
    {
        if (!cur)return;
        result.push_back(cur->val);
        preorderTraversal1(cur->left, result);
        preorderTraversal1(cur->right, result);
    }

private:

};
int main()
{
    std::vector<char> preorder = { '1', '2', '3', '\0','\0','4','5','\0','\0','6','\0','\0','7' };
    TreeNode<char>* root = buildTreeFromPreorder(preorder);
    Solution S;
    std::vector<char> result = S.preorderTraversal(root);
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
