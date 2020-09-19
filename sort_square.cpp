#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    IOS;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int out[n];
    int l = n-1,i = 0,j = n-1;
    while(l>=0)
    {
        if(abs(arr[i])<abs(arr[j]))
        {
            out[l] = arr[j]*arr[j];
            j--;
        }
        else
        {
            out[l] = arr[i]*arr[i];
            i++;
        }
        l--;
    }
    for(int i:out)
        cout<<i<<" ";
}