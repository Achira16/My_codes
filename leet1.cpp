#include<bits/stdc++.h>
using namespace std;
int calc(int arr[],int n,int k)
{
    if(k <= 1)   //constraint: minimum no. in the array is >= 1. No 0.
        return 0;
    int mul = 1,count = 0,j = 0,ans = 0;
    for(int i=0;i<n;i++)
    {
        mul*=arr[i];
        count++;
        while(mul>=k && j<n)
        {
            mul/=arr[j++];
            if(count>0)
                count--;
        }
        if(j>i)
            i = j-1;
        ans+=count;
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)    
        cin>>arr[i];
    int ans = calc(arr,n,k);
    cout<<ans;
}