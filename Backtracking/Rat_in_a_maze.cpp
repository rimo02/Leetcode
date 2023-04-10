#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 4
int solveMazeRec(int maze[N][N], int x, int y, int i, int arr[N][N]);
int isSafe(int maze[N][N], int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}
void printSol(int maze[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << " " << setw(2) << maze[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
}
int solveMaze(int maze[N][N])
{
    int arr[N][N] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};
    if (solveMazeRec(maze, 0, 0, 1, arr) == 0)
    {
        cout << "Solution Does not exist";
        return 0;
    }
    cout << "\n"
         << "Maze" << endl;
    printSol(maze);
    cout << "\n"
         << "Solution" << endl;
    printSol(arr);
    return 1;
}
int solveMazeRec(int maze[N][N], int x, int y, int i, int arr[N][N])
{
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        arr[x][y] = 1;
        return 1;
    }
    if (isSafe(maze, x, y) == 1)
    {
        if (arr[x][y] == i)
        {
            return 0;
        }
        arr[x][y] = i;
        if (solveMazeRec(maze, x + 1, y, i + 1, arr) == 1)
        {
            return 1;
        }
        if (solveMazeRec(maze, x, y + 1, i + 1, arr) == 1)
        {
            return 1;
        }
        if (solveMazeRec(maze, x - 1, y, i + 1, arr) == 1)
        {
            return 1;
        }
        if (solveMazeRec(maze, x, y - 1, i + 1, arr) == 1)
        {
            return 1;
        }
        arr[x][y] = 0;
        return 0;
    }
    return 0;
}
int main()
{
    int maze[N][N] = {{1, 1, 1, 0},
                      {0, 1, 1, 1},
                      {0, 1, 1, 0},
                      {1, 1, 1, 1}};
    solveMaze(maze);
}