#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll multiply(ll n,vector<int>& res,ll nod)
{
    ll prod,c=0;
    for(ll i=0;i<nod;i++)
    {
        prod = res[i]*n+c;
        res[i] = prod%10;
        c = prod/10;
    }
    while(c)
    {
        res.push_back(c%10);
        nod++;
        c/=10;
    }
    return nod;
}
void power(ll n)
{
    vector<int> res;
    ll nod = 0;
    ll temp = n;
    while(temp)
    {
        res.push_back(temp%10);
        nod++;
        temp/=10;
    }
    for(ll i=2;i<=n;i++)
    {
        nod = multiply(n,res,nod);
    }
    for(ll i=nod-1;i>=0;i--)
        cout<<res[i];
}
int main()
{
    ll n = 1e9;
    power(n);
}