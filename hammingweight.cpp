#include<bits/stdc++.h>
using namespace std;

int solve(uint32_t n)
{
    int ans = 0;
    for(uint32_t val=n;val>0;ans++)
    {
        val = val&(val-1);
    }
    return ans;
}
int main()
{
    uint32_t n;
    cin>>n;
    cout<<solve(n);
}