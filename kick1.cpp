#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

long fun(long g)
{
    long ans = 1;
    for(long i=1;i*(i+1)<2*g;i++)
    {
        double a = (1.0*g - (i*(i+1))/2)/(i+1);
        if(a-long(a) == 0.0)
         ans++;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        long g;
        cin>>g;
        cout<<"Case #"<<i<<": "<<fun(g)<<"\n";
    }
}