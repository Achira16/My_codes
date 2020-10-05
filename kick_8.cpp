#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

const int N = 1e5;
int arr[N],p[2*100*N+1];
void solve(int n,int negsum,int possum)
{
    int ans = 0,sum = 0;
    p[negsum]++;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        for(int j=0;j*j<=possum;j++)
        {
            if(negsum+(sum-j*j)>=0)
                ans+=p[negsum+(sum-j*j)];
        }
        p[sum+negsum]++;
    }
    cout<<ans<<endl;
    memset(p,0,sizeof(p));
}
int main()
{
    IOS;
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        int negsum = 0,possum = 0;
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
            if(arr[j]<0)
                negsum-=arr[j];
            else
                possum+=arr[j];
        }
        cout<<"Case #"<<i<<": ";
        solve(n,negsum,possum);
    }
}