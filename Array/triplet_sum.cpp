#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter a number:";
        cin >> arr[i];
    }
    cout << "Enter the triplet number:";
    int num;
    cin >> num;
    cout<<"The triplet pairs are:"<<endl;
    for(int i=0;i<8;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            for(int k=j+1;k<10;k++)
            {
                if(i+j+k==num)
                {
                    cout<<"("<<i<<","<<j<<","<<k<<")"<<"\t";
                }

            }
        }
    }
}