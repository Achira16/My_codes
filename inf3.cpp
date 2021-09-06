#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& a)
{
    vector<int> dp(a.size(),1);
    for(int i=1;i<a.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i] > a[j] && 2*(a[i]&a[j]) < a[i]|a[j])
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<func(a);
}