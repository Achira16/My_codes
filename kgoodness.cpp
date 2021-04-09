#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int fun(string& s,int k)
{
    int n = s.size(),good = 0;
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
            good++;
    }
    if(good == k)
        return 0;
    else if(good>k)
        return good-k;
    return k-good;
}
int main()
{
    IOS;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int l,k;
        cin>>l>>k;
        string s;
        cin>>s;
        cout<<"Case #"<<i<<": "<<fun(s,k)<<"\n";
    }
}