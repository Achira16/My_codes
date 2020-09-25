#include<bits/stdc++.h>
using namespace std;
void powerset(int arr[],int n)
{
    int s = exp2(n);
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
                cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    powerset(arr,n);
}