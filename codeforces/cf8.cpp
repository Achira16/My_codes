#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

ll power(ll a,ll n){
    ll res = 1;
    while(n){
        if(n&1) res *= a;
        a*=a;
        n>>=1;
    }
    return res;
}

int main(){
    IOS;
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int sum = 0;
        for(auto ele:arr)
            sum += ele;
        int ones = 0,zeros = 0;
        for(auto ele:arr){
            if(ele == 1) ones++;
            else if(ele == 0) zeros++;
        }
        ll ans = power(2,zeros) * ones;
        cout<<ans<<"\n";
    }
}