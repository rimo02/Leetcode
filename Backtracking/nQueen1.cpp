#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSafe1(vector<string> board, int row, int col, int n)
    {
        int trow = row;
        int tcol = col;
        while (trow >= 0 && tcol >= 0)
        {
            if (board[trow][tcol] == 'Q')
                return false;
            trow--;
            tcol--;
        }
        trow = row;
        tcol = col;
        while (tcol >= 0)
        {
            if (board[trow][tcol] == 'Q')
                return false;
            tcol--;
        }
        trow = row;
        tcol = col;
        while (trow < n && tcol >= 0)
        {
            if (board[trow][tcol] == 'Q')
                return false;
            trow++;
            tcol--;
        }
        return true;
    }
    void solve(int n, int col, int &count,
               vector<string> &board, vector<int> &left, vector<int> &upper, vector<int> &lower)
    {
        if (col == n)
        {
            count++;
        }
        for (int row = 0; row < n; row++)
        {
            if (left[row] == 0 && lower[row + col] == 0 && upper[n - 1 + col - row] == 0)
            {
                left[row] = 1;
                lower[row + col] = 1;
                upper[n - 1 + col - row] = 1;
                board[row][col] = 'Q';
                solve(n, col + 1, count, board, left, upper, lower);
                board[row][col] = '.';
                left[row] = 0;
                lower[row + col] = 0;
                upper[n - 1 + col - row] = 0;
            }
        }
    }
    int totalNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        vector<int> left(n, 0);
        vector<int> upper(2 * n);
        vector<int> lower(2 * n);
        int count = 0;
        solve(n, 0, count, board, left, upper, lower);
        return count;
    }
};