#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll func(vector<int>& arr)
{
    int maxel = *max_element(arr.begin(), arr.end());
    ll ans = 0;
    int n = arr.size();
    for(int i=1;i<=maxel;i*=2)
    {
        vector<int> rems(n);
        for(int j=0;j<n;j++)
        {
            rems[j] = (arr[j]/i)&1;
        }
        vector<int> presum(n);
        presum[n-1] = rems[n-1];
        for(int j=n-2;j>=1;j--)
        {
            presum[j] = presum[j+1] + rems[j];
        }
        ll temp = 0;
        for(int j=0;j<n-1;j++)
        {
            temp = ((rems[j]*presum[j+1])%mod + temp%mod)%mod;
        }
        temp = (i%mod * temp%mod)%mod;
        ans = (ans%mod + temp%mod)%mod;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<func(arr);
}