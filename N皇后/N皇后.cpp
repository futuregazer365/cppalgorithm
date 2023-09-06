// N皇后.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
    vector<vector<string>> solveNQueens(int n) {
        if (n <= 3) {
            return vector<vector<string>>();
        }
        else
        {
            vector<string> chessbord(n, std::string(n, '.'));
            backtracking(chessbord, 0);
            return result;
        }
    }
    /*
    row 遍历到了第几行
    */
    void backtracking(vector<string> &chessboard,int row) {
        if (chessboard.size() == row) {
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < chessboard.size(); col++) {
            if (isVaild(chessboard, row, col)) {//合法位置
                chessboard[row][col] = 'Q';
                backtracking(chessboard, row + 1);
                chessboard[row][col] = '.';
            }

        }
    };
    /*
    棋盘摆放位置是否合法
    */
    bool isVaild(const vector<string>& chessboard,int i ,int j) {
        for (int row = 0; row < chessboard.size(); row++) {//同一列有皇后
            if (chessboard[row].at(j) == 'Q') {
                return false;
            }
        }
        for (int row = i, col = j; row < chessboard.size() && col < chessboard.size(); row++, col++) {//右下有皇后
            if (chessboard[row].at(col) == 'Q') {
                return false;
            }
        }
        for (int row = i, col = j; row < chessboard.size() && col < chessboard.size(); row--, col--) {//左上有皇后
            if (chessboard[row].at(col) == 'Q') {
                return false;
            }
        }
        for (int row = i, col = j; row < chessboard.size() && col < chessboard.size(); row--, col++) {//右上有皇后
            if (chessboard[row].at(col) == 'Q') {
                return false;
            }
        }
        for (int row = i, col = j; row < chessboard.size() && col < chessboard.size(); row++, col--) {//左下有皇后
            if (chessboard[row].at(col) == 'Q') {
                return false;
            }
        }
        return true;
    };
    vector<string> chessboard;
    vector<vector<string>> result;
};

int main()
{
    Solution S;
    vector<vector<string>> result = S.solveNQueens(4);
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
