#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int solve(int n)
{
    int sum = 0;
    long power = 1;
    while(n)
    {
        int m = n;
        while(m)
        {
            sum = (m%2 * power%mod + sum%mod)%mod;
            power = (power%mod *2)%mod;
            m/=2;
        }
        n--;
    }
    return sum%mod;
}
int main()
{
    int n;
    cin>>n;
    cout<<solve(n);
}