#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

ll sum(ll x,ll k){
    if(x <= k) return (x*(x+1))/2;
    ll n1 = k-(x-k)-1;
    ll n2 = k-1;
    ll sum = (n2 * (n2+1))/2 - (n1 * (n1+1))/2;
    sum += (k * (k+1))/2;
    return sum;
}
int main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        ll k,x;
        cin>>k>>x;
        ll l = 1,r = 2*k-1;
        ll ans = -1;
        while(l <= r){
            ll mid = l+(r-l)/2;
            ll cur = sum(mid,k);
            if(cur == x){
                ans = mid;
                break;
            }
            else if(cur < x)
                l = mid+1;
            else
                r = mid-1;
        }
        if(ans != -1){
            cout<<ans<<endl;
        }
        else{
            if(l > 2*k-1){
                cout<<2*k-1<<endl;
            }
            else
                cout<<l<<endl;
        }
    }
}