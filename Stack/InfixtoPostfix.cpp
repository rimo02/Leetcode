#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int precision(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infix2postfix(string s)
{
    stack<char> st;
    string result;
    s = '(' + s + ')';
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch >= '0' && ch <= '9')
        {
            result += ch;
        }
        else if (ch == '(')
        {
            st.push('(');
        }
        else if (ch == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop(); // popping '('
        }
        else
        {
            while (!st.empty() && (precision(s[i]) <= precision(st.top())))
            {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    return result;
}
void evaluate(string s)
{
    stack<int> st;
    int result;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch >= '0' && ch <= '9')
        {
            st.push((int)ch - 48);
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            switch (ch)
            {
            case '+':
                result = b + a;
                break;
            case '-':
                result = b - a;
                break;
            case '*':
                result = b * a;
                break;
            case '/':
                result = b / a;
                break;
            case '^':
                result = pow(b, a);
                break;
            }
            st.push(result);
        }
    }
    cout << "Result:" << st.top()<<endl;
}
int main()
{
    string s;
    cout << "Enter the string:";
    cin >> s;
    string res = infix2postfix(s);
    cout << "Infix=" << s<<endl;
    cout << "Postfix=" << res<<endl;
    evaluate(res);
}