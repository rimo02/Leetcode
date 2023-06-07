#include <iostream>
using namespace std;
#define M 5
#define N 5
int findAdj(int mat[M][M], int x, int y, int m, int n)
{
    if (x == m && y == n)
    {
        return 1;
    }
    if (x == m || y == n)
    {
        return 0;
    }
    if (mat[x][y] == 1)
    {
        return 1;
    }
    return findAdj(mat, x + 1, y, m, n) + findAdj(mat, x, y + 1, m, n);
}
int main()
{
    int mat[M][N] = {{0, 0, 0, 0, 1},
                     {0, 1, 0, 1, 0},
                     {0, 0, 0, 0, 0}};
    cout << findAdj(mat, 1, 1, 5, 5);
}