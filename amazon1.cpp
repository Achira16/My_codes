#include<bits/stdc++.h>
using namespace std;

int func(int n,int D)
{
    vector<int> seive(10000,1);
    seive[0] = seive[1] = 0;
    for(int i=2;i*i<10000;i++)
    {
        for(int j=2;j*i<10000;j++)
            seive[i*j] = 0;
    }
    vector<int> primes;
    int count = 0,i = 2;
    while(count < n)
    {
        if(seive[i])
        {
            primes.push_back(i);
            count++;
        }
        i++;
    }
    vector<int> dp(D+1,INT_MAX);
    dp[0] = 0;
    for(int i=2;i<=D;i++)
    {
        for(int j=0;j<primes.size();j++)
        {
            if(primes[j] <= i)
            {
                if(dp[i-primes[j]]!=INT_MAX)
                    dp[i] = min(dp[i],dp[i-primes[j]]+1);
            }
        }
    }
    return dp[D];
}
int main()
{
    int n,D;
    cin>>D>>n;
    cout<<func(n,D);
}