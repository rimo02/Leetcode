// Catalan numbers are defined as a mathematical sequence that consists of positive integers, which can be used to find the number of possibilities of various combinations.
// The nth term in the sequence denoted Cn, is found in the following formula: \frac{(2n)!}{(n + 1)! n!)}
// Catalan numbers occur in many interesting counting problems like the following.

// Count the number of expressions containing n pairs of parentheses that are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
// Count the number of possible Binary Search Trees with n keys (See this)
// Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
// Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.
#include <iostream>
using namespace std;
int catalan(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalan(i) * catalan(n - 1 - i);
    }
    return res;
}
int catalanDP(int n)
{
    int arr[n + 2];
    arr[0] = arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = 0;
        for (int j = 0; j < i; j++)
        {
            arr[i] += catalanDP(j) * catalanDP(i - j - 1);
        }
    }
    return arr[n];
}

int main()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    cout << "Recursively: " << catalan(n) << endl;
    cout << "Dynamic Programming: " << catalanDP(n) << endl;
}