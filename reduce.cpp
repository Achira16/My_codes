#include<bits/stdc++.h>
using namespace std;

//we need minimum boundary elements to add upto X ...which means continuous maximum no. of inner elements should add upto total sum-x
int calc(vector<int>& arr,int x)
{
    int n = arr.size(),sum = 0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    sum = sum-x;
    int maxl = -1,j = 0,temp_sum = 0;
    for(int i=0;i<n;i++)
    {
        temp_sum += arr[i];
        while(j<i && temp_sum>sum)
        {
            temp_sum -= arr[j++];
        }
        if(temp_sum == sum)
            maxl = max(maxl,i-j+1);
    }
    if(maxl == -1)
        return -1;
    return n-maxl;
}
int main()
{
    int x,n;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<calc(arr,x);
}