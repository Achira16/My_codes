#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

int main(){
    IOS;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        ll sum = 0;
        for(auto el:arr)
            sum += el;
        ll x = sum%n;
        cout<<x*(n-x)<<"\n";
    }
    
}