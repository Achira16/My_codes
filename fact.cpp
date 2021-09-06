#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<double> logs(3001);
double power(double n)
{
    if(n < 2)
        return exp2(n)%mod;
    double ans = power(n/2);
    ans = ((ans%mod)*(ans%mod))%mod;
    return ans;
}
void precomp()
{
    for(int i=2;i<=3000;i++)
    {
        logs[i] = log2(i)+logs[i-1];
    }
}
int main()
{
    precomp();
    cout<<power(logs[4]);
}