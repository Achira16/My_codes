#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

int main(){
    IOS;
    int t;
    cin>>t;
    while (t--)
    {
        ll a,b;
        cin>>a>>b;
        if(a == b){
            cout<<0<<" "<<0<<endl; 
        }
        else if(a == 0 || b == 0){
            cout<<abs(a-b)<<" "<<0<<endl;
        }
        else{
            ll maxexc = abs(a-b);
            ll minel = min(a,b);
            ll rem = minel%maxexc;
            if(minel - rem >= 0){
                cout<<maxexc<<" "<<min(rem,maxexc - rem)<<endl;
            }
            else{
                cout<<maxexc<<" "<<maxexc-rem<<endl;
            }
        }
    }
}