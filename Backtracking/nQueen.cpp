#include <iostream>
using namespace std;
#define N 8
int nqueenRec(int col, int i, int board[N][N]);
void printsol(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
int nqueen(int board[N][N])
{
    // board[0][0] = 1;
    if (nqueenRec(0, 1, board) == 0)
    {
        cout << "Solution not possible";
        return 0;
    }
    printsol(board);
    return 1;
}
int isSafe(int col, int row, int board[N][N])
{
    for (int i = row, j = col; i <= N - 1 && j >= 0; i++, j--)
    {
        if (board[i][j] >= 1)
            return 0;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] >= 1)
            return 0;
    }
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] >= 1)
            return 0;
    }
    return 1;
}
int nqueenRec(int col, int i, int board[N][N])
{
    if (i > N)
    {
        return 1;
    }
    for (int k = 0; k < N; k++)
    {
        if (isSafe(col, k, board))
        {
            board[k][col] = i;
            if (nqueenRec(col + 1, i + 1, board))
            {
                return 1;
            }
            board[k][col] = 0;
        }
    }
    return 0;
}
int main()
{
    int board[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
    nqueen(board);
}