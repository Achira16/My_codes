#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int calc(vector<int>& arr,int k)
{
    int n = arr.size();
    int ans = 0,count = 0;
    bool check_countdown = false;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == k)
        {
            check_countdown = true;
            count = 1;
        }
        else if (check_countdown)
        {
            if(arr[i] == arr[i-1]-1)
                count++;
            else
                check_countdown = false;
            if(count == k)
            {
                ans++;
                check_countdown = false;
            }
        }
        
    }
    return ans;
}
int main()
{
    IOS;
    int t,n,k;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int ans = calc(arr,k);
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}
