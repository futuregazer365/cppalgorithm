// 从中序与后序遍历数组构建二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// leetcode 106
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

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
    TreeNode<T>* buildTree(vector<T>& inorder, vector<T>& postorder) {
        if (postorder.empty()) 
        {
            return nullptr;
        }
        int rootval = postorder[postorder.size() - 1];
        TreeNode<T>* root = new TreeNode<T>(rootval);
        if (postorder.size() == 1) 
        {
            return root;
        }
        //查找分割位置
        int  delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) 
        {
            if (inorder[delimiterIndex] == rootval) {
                break;
            }
        }
        //分割中序数组
        auto iter = inorder.begin();
        int count = delimiterIndex;
        while (count--)
        {
            iter++;
        }
        vector<int> leftinorder(inorder.begin(), iter);
        vector<int> rightinorder(iter+1, inorder.end());
        //分割后续数组
        postorder.resize(postorder.size() - 1);
        int leftsplit = leftinorder.size() - 1 + 1;//左闭右开
        iter = postorder.begin();
        while (leftsplit--)
        {
            iter++;
        }
        vector<int> leftpostorder(postorder.begin(), iter);//为什么这里不会越界呢，因为一个节点存在必须有一个值，leftinorder最大等于inorder的大小-1，假设inorder大小为5
        vector<int> rightpostorder(iter, postorder.end());//leftinorder最大为4，此时leftsplit4，也就是说没有右子树了， 切割postorder【0，iter)，此时iter在postorder.end()

        root->left = buildTree(leftinorder, leftpostorder);
        root->right = buildTree(rightinorder, rightpostorder);

        return root;
    }
};
int main()
{
    vector<int> Arrs{ 1,2,3,4,5,6,7,8,9 }; // 假设有这么个数组,要截取中间第二个元素到第四个元素：2，3，4
    vector<int>::const_iterator First = Arrs.end()-1;
    vector<int>::const_iterator Second = Arrs.end();
    vector<int> Arrs2(First, Second); // 将值直接初始化到Arrs2 这种方式分割是[First，Second）

    vector<int> inorder = { 9,3,15,20,7 };
    vector<int> postorder = { 9,15,7,20,3 };
    Solution<int> S;
    TreeNode<int>* root = S.buildTree(inorder, postorder);
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
