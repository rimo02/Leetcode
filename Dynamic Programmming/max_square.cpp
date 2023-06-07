#include <iostream>
using namespace std;
#define R 6
#define C 5


int main()
{
    bool M[R][C] = {{0, 1, 1, 0, 1}, {1, 1, 0, 1, 0}, {0, 1, 1, 1, 0}, {1, 1, 1, 1, 0}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 0}};
    printMaxSubSquare(M);
}