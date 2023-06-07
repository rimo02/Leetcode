#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 5
int solveKTRec(int x, int y, int i, int arr[N][N], int xMove[], int yMove[]);
int isSafe(int x, int y, int arr[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && arr[x][y] == -1);
}
void printsol(int arr[N][N])
{
    cout<<endl;
    cout<<endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << " " << setw(2) << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int solveKT()
{
    int arr[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = -1;
        }
    }
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    // int xMove[8] = {-1, 2, 1, -2, -1, 1, 2, -2};
    // int yMove[8] = {2, -1, -2, 1, -2, 2, 1, -1};
    arr[0][0] = 0;
    if (solveKTRec(0, 0, 1, arr, xMove, yMove) == 0)
    {
        cout << "Solution does not exist";
        return 0;
    }
    else
    {
        printsol(arr);
    }
    return 1;
}
int solveKTRec(int x, int y, int i, int arr[N][N], int xMove[8], int yMove[8])
{
    int k, nextx, nexty;
    if (i == N * N)
    {
        return 1;
    }
    for (k = 0; k < 8; k++)
    {
        nextx = x + xMove[k];
        nexty = y + yMove[k];
        if (isSafe(nextx, nexty, arr))
        {
            arr[nextx][nexty] = i;
            // printsol(arr);
            if (solveKTRec(nextx, nexty, i + 1, arr, xMove, yMove) == 1)
            {
                return 1;
            }
            else
            {
                arr[nextx][nexty] = -1;
            }
        }
    }
    return 0;
}
int main()
{
    solveKT();
    return 0;
}