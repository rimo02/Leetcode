#include<iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr;
    for(int i=0;i<10;i++)
    {
        cout<<"Enter a number:";
        int n;
        cin>>n;
        arr.push_back(n);
    }
    for(auto i=arr.begin();i!=arr.end();i++)
    {
        cout<<*i<<" ";
    }
}