// #include <iostream>
// using namespace std;
// int recursion(string s1, string s2, int m, int n)
// {
//     if (n == s2.size())
//         return 1;
//     if (m == s2.size())
//         return 0;
//     int count = 0;
//     if (s1[m] == s2[n])
//     {
//         count += recursion(s1, s2, m + 1, n + 1);
//         count += recursion(s1, s2, m + 1, n);
//     }
//     else
//     {
//         count += recursion(s1, s2, m, n + 1);
//     }
//     return count;
// }
// int main()
// {
//     string s1 = "ccc";
//     string s2 = "cccc";
//     cout << recursion(s1, s2, 0, 0);
// }

#include <iostream>
#include <string>

int countWays(const std::string &s1, const std::string &s2, int idx1, int idx2)
{
    // If we've matched all characters in s2, it's a valid subsequence
    if (idx2 == s2.length())
    {
        return 1;
    }

    // If we've exhausted s1 or s2 has characters left but s1 doesn't, no valid subsequence can be formed
    if (idx1 == s1.length())
    {
        return 0;
    }

    int ways = 0;

    // If the characters match, move in both strings to check for more subsequences
    if (s1[idx1] == s2[idx2])
    {
        ways += countWays(s1, s2, idx1 + 1, idx2 + 1); // Include the character
    }

    // Move to the next character in s1
    ways += countWays(s1, s2, idx1 + 1, idx2); // Exclude the character

    return ways;
}

int main()
{
    std::string s1 = "ababa";
    std::string s2 = "aba";

    int ways = countWays(s1, s2, 0, 0);

    std::cout << "Possible ways to recover s2 by deleting characters from s1: " << ways << std::endl;

    return 0;
}
