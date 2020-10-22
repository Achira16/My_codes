#include<bits/stdc++.h>
using namespace std;

long power(long n,int p)
{
    if(p==0)
        return 1;
    if(p==1)
        return n;
    long res = power(n,p/2);
    if(p&1)
        return res*res*n;
    return res*res;
}
int main()
{
    long n;
    cin>>n;
    if(!n)
    {
        cout<<1;
        return -1;
    }
    int b = log2(n) + 1;
    long val = power(2,b)-1;
    val-=n;
    cout<<val;
}