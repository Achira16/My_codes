#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> primes(n,1);
    primes[0] = primes[1] = 0;
    for(int i=2;i*i<n;i++)
    {
        for(int j=2;j*i<n;j++)
            primes[i*j] = 0;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(primes[i])
        {
            cout<<i;
            break;
        }
    }
}