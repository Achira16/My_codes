#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

int main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll sum = 0,a;
        for(int i = 0; i < n; i++){
            cin>>a;
            sum += a;
        }
        if(sum%n == 0) cout<<0<<endl;
        else cout<<1<<endl;
    }
}